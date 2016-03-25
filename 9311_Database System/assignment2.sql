create view Q1(Name) as
	select Name
	from Person 
	where PersonId in(
		select PersonId
		from RelationPersonInProceeding
	);

create view Q2(Name) as
	with
		/*find out all authors who are editors*/
		A as
		(select distinct relationpersoninproceeding.personid
		from relationpersoninproceeding, proceeding
		where relationpersoninproceeding.personid = proceeding.editorid
		),
		/*find out the authors' personid that have nerver been an editor*/
		B as
		(select distinct personid
		from relationpersoninproceeding
		where relationpersoninproceeding.personid not in
		(select personid from A)
		)
	select person.name
	from person, B
	where person.personid = B.personid
	order by person.name;

create view Q3(Name) as
	with
		/*find out the editors who edit their own papers in a proceeding*/
		A as
		(select distinct proceeding.editorid
		from proceeding , inproceeding, relationpersoninproceeding
		where proceeding.proceedingid = inproceeding.proceedingid
		and relationpersoninproceeding.inproceedingid = inproceeding.inproceedingid
		and proceeding.editorid = relationpersoninproceeding.personid
		),
		/*find out the editors who never edit their own papers*/
		B as
		(select distinct editorid
		from proceeding
		where editorid not in
		(select editorid from A)
		)
	select name
	from person, B
	where person.personid = B.editorid
	order by person.name;

create view Q4(Name, Total) as
	select person.name, count(proceeding.editorid)
	from proceeding,inproceeding,relationpersoninproceeding,person
	where proceeding.proceedingid = inproceeding.proceedingid
	and inproceeding.inproceedingid = relationpersoninproceeding.inproceedingid
	and proceeding.editorid = relationpersoninproceeding.personid
	and person.personid = proceeding.editorid
	group by person.name
	order by count(proceeding.editorid) DESC,person.name;

create view Q5(Title) as
	with
		/*find out all papers' editors and publishing year*/
		A as
		(select inproceeding.inproceedingid, proceeding.year, relationpersoninproceeding.personid
		from proceeding, inproceeding, relationpersoninproceeding
		where inproceeding.proceedingid = proceeding.proceedingid
		and relationpersoninproceeding.inproceedingid = inproceeding.inproceedingid
		),
		/*find out the first year of every editor as an editor in a proceeding*/
		B as
		(select editorid, min(year)as firstYear
		from proceeding
		group by editorid),
		/*find out all papers which at least one of the their authors had been a editor before the paper published*/
		C as
		(select A.inproceedingid, A.year, A.personid, B.firstYear
		from A left join B on A.personid = B.editorid
		where B.firstYear < A.year
		),
		/*find out all the inproceedingid*/
		D as
		(select distinct inproceeding.inproceedingid
		from proceeding, inproceeding
		where inproceeding.proceedingid = proceeding.proceedingid
		and inproceeding.inproceedingid not in
		(select inproceedingid from C)
		)
	select inproceeding.title
	from inproceeding, D
	where inproceeding.inproceedingid = D.inproceedingid
	order by inproceeding.title;

create view Q6(Year, Total) as
	select proceeding.year,count(inproceeding.inproceedingid)
	from proceeding, inproceeding
	where proceeding.proceedingid = inproceeding.proceedingid
	group by proceeding.year
	order by proceeding.year;

create view Q7(Name) as 
	/*calculate the number of paper of every publsher*/
 	with
		A as
		(select proceeding.publisherid, count(inproceeding.inproceedingid) as count
		from proceeding, inproceeding
		where proceeding.proceedingid = inproceeding.proceedingid
		group by proceeding.publisherid
		)
	select publisher.name
	from publisher, A
	where publisher.publisherid = A.publisherid
	and A.count = (select max(count) from A);


create view Q8(Name) as 
 	with 
 		/*find out all the co-authors of every author*/
 		A as (
        select a.personid, a.inproceedingid
        from relationpersoninproceeding a, relationpersoninproceeding b
        where a.inproceedingid = b.inproceedingid 
        and a.personid <> b.personid
        group by a.personid, a.inproceedingid
        order by a.inproceedingid
        ),
        /*calculate the number of co-author of every author*/ 
 		B as (
        select A.personid, count(a.personid) as count
        from A
        group by a.personid
        order by count(a.personid) desc
        )
 	select person.name
  	from B, person
	where B.personid = person.personid and B.count = ( select max(B.count) as max
           from B);

CREATE VIEW Q9(Name) AS 
	with 
		/*find out all the co-authors of every authors*/
		A as
		(select X.personid
		from relationpersoninproceeding as X, relationpersoninproceeding as Y
		where X.inproceedingid = Y.inproceedingid
		and X.personid <> Y.personid
		group by X.personid
		),
		/*find out the authors who have no co-author*/
		B as
		(select distinct personid
		from relationpersoninproceeding
		where relationpersoninproceeding.personid not in
			(select personid
			from A
			)
		)
	select person.name
	from person, B
	where person.personid = B.personid
	order by person.name;


CREATE VIEW Q10(Name, Total) AS 
	with
		/*find out all the co-authors of every author*/
		A as
		(select X.personid as XP,Y.personid as YP
		from relationpersoninproceeding as X, relationpersoninproceeding as Y
		where X.inproceedingid = Y.inproceedingid
		and X.personid <> Y.personid
		group by X.personid,Y.personid
		),
		/*calculate the number of co-authors of each author*/
		B as
		(select XP, count(XP) as count
		from A
		group by XP
		),
		/*find out the authors who have no co-author*/
		C as
		(select distinct personid
		from relationpersoninproceeding
		where relationpersoninproceeding.personid not in
			(select XP from B)
		)
	select person.name,B.count as total
	from B, person
	where B.XP = person.personid
	union all
	select person.name, 0
	from C, person
	where C.personid = person.personid
	order by total desc, name;

create view Q11(Name) as
	with 
		/*find out all the co-authors of every author*/
		A as
		(select X.personid as XP,Y.personid as YP
		from relationpersoninproceeding as X, relationpersoninproceeding as Y
		where X.inproceedingid = Y.inproceedingid
		and X.personid <> Y.personid
		group by X.personid,Y.personid
		),
		/*find out the author whose first name or co-author's first name is Richard*/
		B as
		(select A.YP
		from person, A
		where person.personid = A.XP
		and person.name ~ '^Richard'
		union
		select person.personid
		from relationpersoninproceeding, person
		where relationpersoninproceeding.personid = person.personid
		and person.name ~'^Richard'
		),
		/*find out the author who have the co-author named Richard*/
		C as
		(select A.XP
		from A, B 
		where A.YP = B.YP
		),
		/*findo out the author who never co-author with Richard*/
		D as 
		(select distinct personid
		from relationpersoninproceeding
		where personid not in
			(select * from C)
		)
	select person.name
	from person,D
	where person.personid = D.personid
	and person.name ~'^(?!Richard)'
	order by person.name;

/*find out all the co-authors of every author*/
create view AssQ12 as (
	select A.personid as author, B.personid as coAuthor
	from relationpersoninproceeding as A, relationpersoninproceeding as B
	where A.inproceedingid = B.inproceedingid
	and A.personid <> B.personid
);
create view Q12(Name) as
	with
		recursive cte as (
		    select AssQ12.coAuthor as coAuthor
		    from AssQ12, person
		    where AssQ12.author = person.personid
		    and person.name ~ '^Richard'
		  union
		    select AssQ12.coAuthor
		    from AssQ12, cte
		    where cte.coAuthor = AssQ12.author
		)
	select person.name
	from cte,person
	where cte.coAuthor = person.personid
	order by person.name;

create view Q13(Author, Total, FirstYear, LastYear) as
 	with 
 		/*find out the authors of every papers*/
		A as
		(select relationpersoninproceeding.personid,inproceeding.proceedingid
		from inproceeding,relationpersoninproceeding
		where inproceeding.inproceedingid = relationpersoninproceeding.inproceedingid
		),
		/*calculate the total number of publications, the first publishing year and the last publishing year of an author*/
		B as
		(select A.personid, count(A.personid)as count, max(proceeding.year)as max, min(proceeding.year)as min
		from A left join proceeding on proceeding.proceedingid = A.proceedingid
		group by personid
		)
	select person.name, b.count, 
	(case when(b.min is null) then 'unknown' else b.min end),
	(case when(b.max is null) then 'unknown' else b.max end)
	from B,person
	where person.personid = B.personid
	order by b.count desc, person.name;
	

create view Q14(Total) as
	with
		/*find out the papers which their titles or proceeding titles contain 'data'*/ 
		A as
		(select inproceedingid
		from inproceeding
		where title ~ '[Dd][Aa][Tt][Aa]'
		union
		select inproceeding.inproceedingid
		from inproceeding,proceeding
		where inproceeding.proceedingid = proceeding.proceedingid
		and proceeding.title ~ '[Dd][Aa][Tt][Aa]'
		)
	select count(distinct relationpersoninproceeding.personid)
	from A,inproceeding,relationpersoninproceeding
	where A.inproceedingid = inproceeding.inproceedingid
	and inproceeding.inproceedingid = relationpersoninproceeding.inproceedingid;
  
create view Q15(EditorName, Title, PublisherName, Year, Total) as
  	with
  		/*calculate the number of papers in every proceeding*/
		A as
		(select proceeding.proceedingid,count(inproceeding.inproceedingid) as count
		from proceeding left join inproceeding on proceeding.proceedingid = inproceeding.proceedingid
		group by proceeding.proceedingid
		),
		/*find out many attributes of the proceeding which publishing paper is more than 0*/
		B as
		(select proceeding.proceedingid, proceeding.editorid, proceeding.title, proceeding.publisherid, proceeding.year, A.count
		from A left join proceeding on A.proceedingid = proceeding.proceedingid
		),
		/*find out the proceeding title, publisherid, publishing id and the number of papers of every editor*/
		C as
		(select person.name, B.title, B.publisherid, B.year, B.count
		from B left join person on person.personid = B.editorid
		)
	select C.name, C.title, publisher.name, C.year, C.count
	from C left join publisher on publisher.publisherid = C.publisherid
	order by C.count desc, C.year, C.title;

create view Q16(Name) as
	with
		/*calculate the number of authors of every paper*/
		A as
		(select inproceedingid, count(personid) as count
		from relationpersoninproceeding
		group by inproceedingid
		),
		/*find out the author who wrote at least 1 paper without co-author*/
		B as
		(select relationpersoninproceeding.personid
		from A,relationpersoninproceeding
		where count = 1
		and A.inproceedingid = relationpersoninproceeding.inproceedingid
		),
		/*find out the author who never be a sole author and an editor*/
		C as
		(select distinct personid
		from relationpersoninproceeding
		where personid not in
		(select personid from B)
		except
		select editorid
		from proceeding
		)
	select person.name
	from person, C
	where person.personid = C.personid
	order by person.name;

create view Q17(Name, Total) as
	with
		/*find out every paper's author*/
		A as
		(select distinct relationpersoninproceeding.personid, inproceeding.proceedingid
		from relationpersoninproceeding, inproceeding
		where relationpersoninproceeding.inproceedingid = inproceeding.inproceedingid
		),
		/*calculate the number of published paper of every author*/
		B as
		(select personid, count(proceedingid) as count
		from A
		group by personid
		)
	select person.name, B.count
	from B, person
	where B.personid = person.personid
	and B.count > 0
	order by B.count desc, person.name;

create view Q18(MinPub, AvgPub, MaxPub) as
	with 
		/*calculate the number of published paper of every author*/
		A as
		(select relationpersoninproceeding.personid, count(inproceeding.inproceedingid) as count
		from relationpersoninproceeding, inproceeding
		where relationpersoninproceeding.inproceedingid = inproceeding.inproceedingid
		group by relationpersoninproceeding.personid
		)
	select min(count), round(avg(count)), max(count)
	from A;

create view Q19(Name, Years, MinPub, MaxPub, AvgPub) as
	with
		/*calculate the number of publicatons per editor per year*/
		A as
		(select proceeding.editorid,proceeding.year,count(inproceeding.inproceedingid) as count
		from proceeding,inproceeding
		where proceeding.proceedingid = inproceeding.proceedingid
		and editorid is not null
		group by proceeding.editorid,proceeding.year
		order by proceeding.editorid
		),
		/*calculate the information about the years of an editor as an editor*/
		B as
		(select editorid, count(year)as years, min(count) min, round(avg(count)) avg, max(count) max
		from A
		where count > 0
		group by editorid
	)
	select person.name, B.years, B.min, B.max, B.avg
	from person, B
	where person.personid = B.editorid
	order by person.name;


create function checkA() returns trigger
as $$
declare 
   count integer;
begin
   select count(proceeding.editorid) into count
   from proceeding, inproceeding
   where inproceeding.inproceedingid = new.inproceedingid 
   and inproceeding.proceedingid = proceeding.proceedingid
   and proceeding.editorid = new.personid;
   if (count > 0) then
   raise exception 'denied';
   end if;
   return new;
end;
$$ language plpgsql;
create trigger aa
before insert or update
on relationpersoninproceeding 
for each row execute procedure checkA();

create function checkB() returns trigger
as $$
declare 
   count integer;
begin
   if(new.year is null)then
	return new;
   else
	select count(inproceeding.inproceedingid) into count
	from proceeding, inproceeding, relationpersoninproceeding
	where inproceeding.inproceedingid = relationpersoninproceeding.inproceedingid
	and relationpersoninproceeding.personid = new.editorid
	and proceeding.proceedingid = inproceeding.proceedingid
	and proceeding.year <= new.year;
	if(count < 3)then
		raise exception 'denied';
	end if;
	return new;
   end if;
end;
$$ language plpgsql;
create trigger bb
before insert or update
on proceeding 
for each row execute procedure checkB();

create function checkC() returns trigger
as $$
declare 
   count integer;
begin
   select count(relationpersoninproceeding.personid) into count
   from proceeding, inproceeding, relationpersoninproceeding
   where proceeding.proceedingid = new.proceedingid
   and proceeding.proceedingid = inproceeding.proceedingid
   and relationpersoninproceeding.personid = proceeding.editorid
   and relationpersoninproceeding.inproceedingid = inproceeding.inproceedingid;
   if(count >= 2)then
	raise exception 'denied';
   end if;
   return new;
end;
$$ language plpgsql;
create trigger cc
before insert or update
on inproceeding 
for each row execute procedure checkC();