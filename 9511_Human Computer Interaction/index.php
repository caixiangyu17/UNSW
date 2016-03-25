<!DOCTYPE html>
<html>
<head>
<!-- 1.9.28 -->
<title>UNSW Moodle: Authentication choice</title>
<link rel="shortcut icon" href="https://moodle.telt.unsw.edu.au/theme/image.php/unsw/theme/1407333028/favicon">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" /><script type="text/javascript">window.NREUM||(NREUM={}),__nr_require=function(t,n,e){function r(e){if(!n[e]){var o=n[e]={exports:{}};t[e][0].call(o.exports,function(n){var o=t[e][1][n];return r(o?o:n)},o,o.exports)}return n[e].exports}if("function"==typeof __nr_require)return __nr_require;for(var o=0;o<e.length;o++)r(e[o]);return r}({D5DuLP:[function(t,n){function e(t,n){var e=r[t];return e?e.apply(this,n):(o[t]||(o[t]=[]),void o[t].push(n))}var r={},o={};n.exports=e,e.queues=o,e.handlers=r},{}],handle:[function(t,n){n.exports=t("D5DuLP")},{}],G9z0Bl:[function(t,n){function e(){var t=l.info=NREUM.info;if(t&&t.agent&&t.licenseKey&&t.applicationID&&p&&p.body){l.proto="https"===f.split(":")[0]||t.sslForHttp?"https://":"http://",i("mark",["onload",a()]);var n=p.createElement("script");n.src=l.proto+t.agent,p.body.appendChild(n)}}function r(){"complete"===p.readyState&&o()}function o(){i("mark",["domContent",a()])}function a(){return(new Date).getTime()}var i=t("handle"),u=window,p=u.document,s="addEventListener",c="attachEvent",f=(""+location).split("?")[0],l=n.exports={offset:a(),origin:f,features:[]};p[s]?(p[s]("DOMContentLoaded",o,!1),u[s]("load",e,!1)):(p[c]("onreadystatechange",r),u[c]("onload",e)),i("mark",["firstbyte",a()])},{handle:"D5DuLP"}],loader:[function(t,n){n.exports=t("G9z0Bl")},{}]},{},["G9z0Bl"]);</script>
<meta name="keywords" content="moodle, UNSW Moodle: Authentication choice" />
<script type="text/javascript">
//<![CDATA[
var M = {}; M.yui = {};
M.pageloadstarttime = new Date();
M.cfg = {"wwwroot":"https:\/\/moodle.telt.unsw.edu.au","sesskey":"stX8fp9uch","loadingicon":"https:\/\/moodle.telt.unsw.edu.au\/theme\/image.php\/unsw\/core\/1407333028\/i\/loading_small","themerev":"1407333028","slasharguments":1,"theme":"unsw","jsrev":"1407333028","svgicons":true};var yui1ConfigFn = function(me) {if(/-skin|reset|fonts|grids|base/.test(me.name)){me.type='css';me.path=me.path.replace(/\.js/,'.css');me.path=me.path.replace(/\/yui2-skin/,'/assets/skins/sam/yui2-skin');}};
var yui2ConfigFn = function(me) {var p = me.path, b = me.name.replace(/^moodle-/,'').split('-', 3), n = b.pop();if (/(skin|core)/.test(n)) {n = b.pop();me.type = 'css';};me.path = b.join('-')+'/'+n+'/'+n;if(me.type !== 'css'){me.path=me.path+'-min';};me.path=me.path+'.'+me.type;};
YUI_config = {"debug":false,"base":"https:\/\/moodle.telt.unsw.edu.au\/lib\/yuilib\/3.9.1\/build\/","comboBase":"https:\/\/moodle.telt.unsw.edu.au\/theme\/yui_combo.php?r1407333028&","combine":true,"filter":null,"insertBefore":"firstthemesheet","groups":{"yui2":{"base":"https:\/\/moodle.telt.unsw.edu.au\/lib\/yuilib\/2in3\/2.9.0\/build\/","comboBase":"https:\/\/moodle.telt.unsw.edu.au\/theme\/yui_combo.php?r1407333028&","combine":true,"ext":false,"root":"2in3\/2.9.0\/build\/","patterns":{"yui2-":{"group":"yui2","configFn":yui1ConfigFn}}},"moodle":{"name":"moodle","base":"https:\/\/moodle.telt.unsw.edu.au\/theme\/yui_combo.php?moodle\/1407333028\/","combine":true,"comboBase":"https:\/\/moodle.telt.unsw.edu.au\/theme\/yui_combo.php?r1407333028&","ext":false,"root":"moodle\/1407333028\/","patterns":{"moodle-":{"group":"moodle","configFn":yui2ConfigFn}},"modules":{"moodle-core-notification":{"requires":["base","node","panel","event-key","dd-plugin"]},"moodle-core-tooltip":{"requires":["base","node","io-base","moodle-core-notification","json-parse","widget-position","widget-position-align","event-outside","cache"]},"moodle-core-popuphelp":{"requires":["moodle-core-tooltip"]},"moodle-core-chooserdialogue":{"requires":["base","panel","moodle-core-notification"]},"moodle-core-blocks":{"requires":["base","node","io","dom","dd","dd-scroll","moodle-core-dragdrop","moodle-core-notification"]},"moodle-core-formchangechecker":{"requires":["base","event-focus"]},"moodle-core-formautosubmit":{"requires":["base","event-key"]},"moodle-calendar-eventmanager":{"requires":["base","node","event-mouseenter","overlay","moodle-calendar-eventmanager-skin"]},"moodle-mod_mediagallery-mediabox":{"requires":["base","node","selector-css3"]},"moodle-mod_mediagallery-base":{"requires":["base","node","selector-css3","dd-constrain","dd-proxy","dd-drop","dd-plugin","moodle-core-notification"]},"moodle-mod_quiz-autosave":{"requires":["base","node","event","event-valuechange","node-event-delegate","io-form"]},"moodle-block_navigation-navigation":{"requires":["base","core_dock","io-base","node","dom","event-custom","event-delegate","json-parse"]},"moodle-filter_glossary-autolinker":{"requires":["base","node","io-base","json-parse","event-delegate","overlay","moodle-core-notification"]},"moodle-editor_tinymce-collapse":{"requires":["base","node","dom"]},"moodle-format_grid-gridkeys":{"requires":["gallery-event-nav-keys"]},"moodle-gradereport_grader-scrollview":{"requires":["base","node"]},"moodle-theme_bootstrapbase-bootstrap":{"requires":["node","selector-css3"]}}}},"modules":{"core_filepicker":{"name":"core_filepicker","fullpath":"https:\/\/moodle.telt.unsw.edu.au\/lib\/javascript.php\/1407333028\/repository\/filepicker.js","requires":["base","node","node-event-simulate","json","async-queue","io-base","io-upload-iframe","io-form","yui2-treeview","panel","cookie","datatable","datatable-sort","resize-plugin","dd-plugin","escape","moodle-core_filepicker"]},"core_dock":{"name":"core_dock","fullpath":"https:\/\/moodle.telt.unsw.edu.au\/lib\/javascript.php\/1407333028\/blocks\/dock.js","requires":["base","node","event-custom","event-mouseenter","event-resize","escape"]}}};
M.yui.loader = {modules: {}};

//]]>
</script>
<script type="text/javascript" src="https://moodle.telt.unsw.edu.au/theme/yui_combo.php?r1407333028&3.9.1/build/simpleyui/simpleyui-min.js&amp;3.9.1/build/loader/loader-min.js"></script><script id="firstthemesheet" type="text/css">/** Required in order to fix style inclusion problems in IE with YUI **/</script><link rel="stylesheet" type="text/css" href="https://moodle.telt.unsw.edu.au/theme/styles.php/unsw/1407333028/all" />
<script type="text/javascript" src="https://moodle.telt.unsw.edu.au/lib/javascript.php/1407333028/lib/javascript-static.js"></script>
<script type="text/javascript" src="https://moodle.telt.unsw.edu.au/theme/javascript.php/unsw/1407333028/head"></script>
</head>
<body id="page-login-index" class="format-site  path-login safari dir-ltr lang-en yui-skin-sam yui3-skin-sam moodle-telt-unsw-edu-au pagelayout-login course-1 context-1 notloggedin content-only has_custome_menu">
<div class="skiplinks"><a class="skip" href="#maincontent">Skip to main content</a></div>
<script type="text/javascript">
//<![CDATA[
document.body.className += ' jsenabled';
//]]>
</script>

<div id="nice_debug_area"></div><div id="page">
  <div id="page-header">
    <div id="logo" class="clearfix">
      <a class="unsw-moodle-logo" href="http://www.unsw.edu.au/">UNSW Moodle</a>
          </div>
        <div id="custommenu" class="clearfix"><div id="custom_menu_1" class="yui3-menu yui3-menu-horizontal javascript-disabled custom-menu"><div class="yui3-menu-content"><ul><li class="yui3-menuitem"><a class="yui3-menuitem-content" title="Moodle Home" href="http://moodle.telt.unsw.edu.au/?redirect=0">Moodle Home</a></li><li class="yui3-menuitem"><a class="yui3-menuitem-content" title="Announcements" href="http://moodle.telt.unsw.edu.au/mod/page/view.php?id=41448">Announcements</a></li><li class="yui3-menuitem"><a class="yui3-menuitem-content" title="User Guides" href="http://moodle.telt.unsw.edu.au/mod/page/view.php?id=41449">User Guides</a></li></ul></div></div></div>
        <div class="headermain"></div>
    <div id="page-heading" class="clearfix">
            <h1>UNSW Moodle</h1>
                  <div class="navbutton"></div>
            <div class="logininfo">You are not logged in. (<a href="https://moodle.telt.unsw.edu.au/login/index.php">Login</a>)</div>    </div>
      </div>
    <div class="navbar clearfix">
    <div class="breadcrumb">
      <span class="accesshide">Page path</span><ul role="navigation"><li><a href="http://moodle.telt.unsw.edu.au/">Home</a></li><li> <span class="accesshide " ><span class="arrow_text">/</span>&nbsp;</span><span class="arrow sep">&#x25BA;</span> <span tabindex="0">Authentication choice</span></li></ul>    </div>
  </div>
    <div id="page-content" class="clearfix">
        <div id="region-main-wrap" class="page-main-content">
      <div id="region-main" class="clearfix">
        <div class="region-content">
        <div role="main"><span id="maincontent"></span><div class="loginbox clearfix">
<div class="loginpanel">
<iframe frameborder="0" height="800" iframe="" marginheight="0" marginwidth="0" scrolling="no" src="https://ssologin.unsw.edu.au/cas/login?service=https://moodle.telt.unsw.edu.au/login/index.php?authCAS=CAS" width="350"></iframe></div>
<div class="signuppanel"><div class="subcontent">        <h2>Looking for help?</h2>
        <div class="text_to_html"><p><strong>UNSW Students </strong>use this <a href="http://teaching.unsw.edu.au/moodle-students">link</a> for all your support needs. <strong>UNSW Staff</strong> use this <a href="http://teaching.unsw.edu.au/moodle">link</a> for all your support needs.</p><p><strong>Alternative logins:</strong><br /><a href="https://moodle.telt.unsw.edu.au/login/agsm-ee/">UNSW Australian Graduate School of Management Executive Education only</a><br /><a href="https://moodle.telt.unsw.edu.au/login/unswglobal/">UNSW Institute of Languages only</a><a href="https://moodle.telt.unsw.edu.au/login/unswglobal/"><br /></a><a href="https://moodle.telt.unsw.edu.au/auth/saml/">Other institutions using Australian Access Federation (AAF)</a></p></div></div></div></div>
</div>        </div>
      </div>
    </div>
  </div>
  <div id="footer-push"></div>
</div>
<div id="footer">
  <div class="clearfix">
    <div class="footer-side-content">
      <div class="homelink"><a href="http://moodle.telt.unsw.edu.au/">Home</a></div>    </div>
    <div class="footer-main-content">
      <ul id="footer-menu" class="unstyled">
        <li><a href="http://www.unsw.edu.au/privacy" target="_blank">Privacy</a></li>
        <li><a href="http://research.unsw.edu.au/content-and-social-media-disclaimer" target="_blank">Content &amp; Social Media Disclaimer</a></li>
        <li><a href="http://www.unsw.edu.au/copyright-disclaimer" target="_blank">Copyright &amp; Disclaimer</a></li>
        <li><a href="http://www.unsw.edu.au/accessibility" target="_blank">Accessibility</a></li>
        <li><a href="http://www.unsw.edu.au/sitemap" target="_blank">Site Map</a></li>
        <li></li>
      </ul>
      <div class="logininfo">You are not logged in. (<a href="https://moodle.telt.unsw.edu.au/login/index.php">Login</a>)</div>    </div>
  </div>
  <div class="clearfix">
    <div id="page-footer">
      <div class="footer-side-content">
        <a href="http://www.unsw.edu.au/" target="_blank" class="footer-logo"></a>
      </div>
      <div class="footer-main-content">
        <p>UNSW staff and students experiencing difficulties using Moodle? Contact External TELT Support for assistance.</p>
        <address>
          Email: <a href="mailto:externalteltsupport@unsw.edu.au">externalteltsupport@unsw.edu.au</a><br>
          Internal: x53331<br>
          External: 9385 3331<br>
          International: +61 2 9385 3331
        </address>
        <p>Page last updated Wednesday 6 August 2014<br>UNSW CRICOS Provider Code 00098G, ABN 57 195 873 179 | Sydney, NSW.2052, Australia</p>
        <a href="#" class="back-to-top">Back to top</a>
        
<script type="text/javascript"> 
//<![CDATA[ 

var _gaq = _gaq || []; 
_gaq.push(['_setAccount', 'UA-9972453-8']); 
_gaq.push(['_trackPageview']); 

(function() { 
var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true; 
ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js'; 
var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(ga, s); 
})(); 

//]]> 
</script><div id="ns_uniqueid" style="display:none;">ns_uniqueid: 00000000:2D6B_00000000:0050_53F9CE63_902408:7BE9</div>      </div>
    </div>
  </div>
</div>
<script type="text/javascript">
//<![CDATA[
M.str = {"moodle":{"lastmodified":"Last modified","name":"Name","error":"Error","info":"Information","filetoolarge":"is too large to upload","morehelp":"More help","loadinghelp":"Loading...","cancel":"Cancel","yes":"Yes"},"repository":{"type":"Type","size":"Size","invalidjson":"Invalid JSON string","nofilesattached":"No files attached","filepicker":"File picker","logout":"Logout","nofilesavailable":"No files available","norepositoriesavailable":"Sorry, none of your current repositories can return files in the required format.","fileexistsdialogheader":"File exists","fileexistsdialog_editor":"A file with that name has already been attached to the text you are editing.","fileexistsdialog_filemanager":"A file with that name has already been attached","renameto":"Rename to \"{$a}\"","referencesexist":"There are {$a} alias\/shortcut files that use this file as their source","select":"Select"},"block":{"addtodock":"Move this to the dock","undockitem":"Undock this item","dockblock":"Dock {$a} block","undockblock":"Undock {$a} block","undockall":"Undock all","hidedockpanel":"Hide the dock panel","hidepanel":"Hide panel"},"langconfig":{"thisdirectionvertical":"btt"},"admin":{"confirmation":"Confirmation"}};
//]]>
</script>
<script type="text/javascript">
//<![CDATA[
YUI().use('node', function(Y) {
M.util.load_flowplayer();
setTimeout("fix_column_widths()", 20);
M.yui.galleryversion="2010.04.08-12-35";Y.use("node-menunav",function() {(function(){M.core_custom_menu.init(Y, "custom_menu_1");
})();
});
M.util.help_popups.setup(Y);
M.yui.galleryversion="2010.04.08-12-35";Y.use("moodle-core-popuphelp",function() {M.core.init_popuphelp();
});
Y.on('domready', function() { M.util.move_debug_messages(Y); });
Y.on('domready', function() { M.util.netspot_perf_info(Y, "00000000:2D6B_00000000:0050_53F9CE63_902408:7BE9", 1408880227.5091); });
M.yui.galleryversion="2010.04.08-12-35";Y.use("moodle-filter_glossary-autolinker",function() {M.filter_glossary.init_filter_autolinking({"courseid":0});
});

});
//]]>
</script>
<script type="text/javascript">window.NREUM||(NREUM={});NREUM.info={"beacon":"beacon-2.newrelic.com","licenseKey":"d6bb71fb66","applicationID":"3373542,3377726","transactionName":"YVMHYkVQWkIAUERQDFgZMEReHlheBlpeFgpYUgBOGUFcQQ==","queueTime":0,"applicationTime":114,"ttGuid":"","agentToken":"","userAttributes":"","errorBeacon":"bam.nr-data.net","agent":"js-agent.newrelic.com\/nr-411.min.js"}</script></body>
</html>
