#include "WString.h"
//#include "FlashMem.h"

String aboutSite = "<!DOCTYPE html>\n<html lang=\"en-GB\">\n<head>\n<meta charset=\"UTF-8\">\n<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n<style> \n*{\nmargin: 0;\npadding: 0;\n/*This got rid of that weird border in the top*/\n}\n@media(min-aspect-ratio:1/1){\n*{\nmargin: 0;\npadding: 0;\nborder: 0;\n/*This got rid of that weird border in the top left*/\n}\n.header{\nfont: 2vw Arial;\nfont-weight: bold;\nmargin-left: 2vw;\n}\n.logs{\nwidth: 90vw;\nmargin: 5vw;\nfont: 2vw arial;\n}\n.playContainer{\nmargin-left: 4.5vw;\nmargin-top: 2vw;\n}\n.Play{\nborder-style: solid;\nborder-width: 4vw;\nborder-color: #202020;\nbox-sizing: border-box;\nwidth: 8vw;\nheight: 8vw;\nborder-width: 4vw 0px 4vw 8vw; \nborder-color: transparenttransparenttransparent#202020; \n}\n.mnavbar{\ndisplay: none;\n}\n.navbar{\ndisplay: grid;\ngrid-template-columns: 10vw 20vw 20vw 20vw 20vw 10vw;\ngrid-template-rows:4vw;\nbackground-color: #028EE6;\nborder-style: solid;\nborder-color: black;\nborder-width: 1px;\nwidth: 100vw;\ntext-align: center;\n}\n.formclass{\ndisplay: grid;\ngrid-template-columns: 25vw 25vw 25vw 25vw;\ngrid-template-rows: 50vw;\n}\n.textInput{\nborder-style: solid;\nborder-color: black;\nborder-width: 4px;\nwidth: 15vw;\nheight: 13vw;\nmargin: 5vw;\nfont: 1vw Arial;\nwhite-space: nowrap;\n}\n.buttonDiv{\npadding-left: 5vw;\n}\n.subButton{\nwidth: 16vw;\nheight: 7vw;\nfont: 4vw Arial;\n}\n.Script{\nborder-radius: 25px;\ndisplay: block;\nborder-style: solid;\nborder-color: black;\nborder-width: 4px;\ntext-align: center;\nbackground-color: #028EE6;\nfont-family: Arial, Helvetica, sans-serif;\nfont: 2vw Arial;\ncolor: black;\nfont-weight: bold;\ntext-decoration: none;\nmargin: auto;\nfloat: left;\nheight: 16vw;\nwidth: 16vw;\nmargin: 4vw;\n} \n.Menu{\ndisplay: block;\nborder-style: solid;\nborder-color: black;\nborder-width: 1px;\ntext-align: center;\nfont-family: Arial, Helvetica, sans-serif;\nfont: 2vw Arial;\ncolor: black;\nfont-weight: bold;\ntext-decoration: none;\n}\n}\n/*Media query for mobile devices. If device screen width is smaller than height then gets treated as mobile device*/\n@media(max-aspect-ratio:1/1){\n*{\nbox-sizing: border-box;\n}\n.header{\nfont: 10vw Arial;\nfont-weight: bold;\nmargin-left: 2vw;\n}\n.logs{\nwidth: 90vw;\nmargin: 5vw;\nfont: 5vw arial; \n}\n.formclass{\ndisplay: grid;\ngrid-template-columns: 50vw 50vw;\ngrid-template-rows: 50vw 50vw;\n}\n.textInput{\nborder-style: solid;\nborder-color: black;\nborder-width: 4px;\nwidth: 40vw;\nheight: 30vw;\nmargin: 5vw;\nfont: 2vw Arial;\nwhite-space: nowrap;\n}\n.buttonDiv{\npadding-left: 18vw;\n}\n.subButton{\nwidth: 14vw;\nheight: 7vw;\nfont: 4vw Arial;\n}\n.blank{display: none;}\n.buttondiv{\ndisplay: grid;\ngrid-template-columns: 40vw 40vw;\ngrid-template-rows: 40vw 40vw;\n}\n.Script{\nborder-radius: 25px;\ndisplay: block;\nborder-style: solid;\nborder-color: black;\nborder-width: 4px;\ntext-align: center;\nbackground-color: #028EE6;\nfont-family: Arial, Helvetica, sans-serif;\nfont: 4vw Arial;\ncolor: black;\nfont-weight: bold;\ntext-decoration: none;\nmargin: auto;\nfloat: left;\nheight: 36vw;\nwidth: 36vw;\nmargin: 10vw;\npadding-top: 4vw;\n} \n.playContainer{\nmargin-left: 10vw;\nmargin-top: 5vw;\n}\n.Play{\nborder-style: solid;\nborder-width: 8vw;\nborder-color: #202020;\nbox-sizing: border-box;\nwidth: 16vw;\nheight: 16vw;\nborder-width: 8vw 0px 8vw 16vw; \nborder-color: transparenttransparenttransparent#202020; \n}\n.Titlebar{\nwidth: 100%;\nfloat: inline-start;\nbackground-color: #028EE6;\n}\n.navbar\n{\ndisplay: none;\n}\n.mnavbar{\nbackground-color: #028EE6;\ntext-align: center;\nfont-family: Arial, Helvetica, sans-serif;\nfont: 7vw Arial;\ntext-decoration: none;\nborder-radius: 25px;\nborder-style: solid;\nborder-color: black;\nborder-width: 4px;\n}\n.DDopen{\ndisplay: block;\ntext-decoration: none;\ncolor: black;\nfont-weight: bold;\n}\n.MMenu{\nwidth: 100%;\ndisplay: block;\nborder-style: solid;\ntext-decoration: none;\ncolor: black;\nborder-width: 4px;\nborder-color: black transparentblack transparent;\n}\n#myDropdown{\ndisplay: none;\n}\n}\n}\n</style>\n<script>\nfunction SHDD(){\ntry{\n//alert(\"test\");//debug test\nvar x = document.getElementById(\"myDropdown\");//passes dom element into variables\n//if dropdown display is block change it to none, else change it to block\nif (x.style.display == \"block\"){\nx.style.display = \"none\";\n}\nelse{\nx.style.display = \"block\";\n}\n}\ncatch(error){\nconsole.error(\"DropDown error: \"+error);\n}\n}\n</script>\n</head>\n<body>\n<div class=\"mobile-container\">\n<div class=\"Titlebar\">\n<a href=\"index.html\"></a>\n</div>\n<div class=\"mnavbar\">\n<a href=\"javascript:void(0);\" class=\"DDopen\" onclick=\"SHDD()\">\nMenu\n</a>\n<div id=\"myDropdown\">\n<a href=\"/index.html\" class=\"MMenu\">Main</a>\n<a href=\"/Edit.html\" class=\"MMenu\">Edit</a>\n<a href=\"/Logs.html\" class=\"MMenu\">Logs</a>\n<a href=\"/About.html\" class=\"MMenu\">About</a>\n<a href=\"javascript:void(0);\" class=\"DDopen\" onclick=\"SHDD()\">Close</a>\n</div>\n</div>\n</div>\n<div class=\"navbar\">\n<div></div>\n<a href=\"/index.html\" class=\"Menu\">Main</a>\n<a href=\"/Edit.html\" class=\"Menu\">Edit</a>\n<a href=\"/Logs.html\" class=\"Menu\">Logs</a>\n<a href=\"/About.html\" class=\"Menu\">About</a>\n<div></div>\n</div>\n<div></div>\n<div class=\"header\">\nAbout\n</div>\n<div class=\"logs\">\n<div>\nThis project is an innovative and exciting endeavor that brings together the power of the ESP32 microcontroller and the versatility of the DuckyScript language. This project enables users to simulate keyboard and mouse input on a computer by programming a script in DuckyScript and uploading it to an ESP32 microcontroller, which then emulates the keyboard and mouse actions on the connected computer.\n</div>\n<br>\n<div>\nThis project is ideal for hobbyists, makers, and tinkerers who want to create custom automation scripts for their computers without having to manually perform repetitive tasks. With the ESP32\'s Wi-Fi capabilities and the ability to connect to a variety of input devices, this project has limitless potential for creative and practical applications.\n</div>\n<br>\n<div>\nWhether you\'re looking to automate your daily routine, streamline your work processes, or just have some fun experimenting with new technology, this HID emulation project is sure to inspire you.\n</div>\n<br>\n<div>\nThis project is open source, which means that anyone can contribute to its development, share their own scripts, and benefit from the knowledge and expertise of the community. There are many exaples of duckyscript available at <a href=\"https://docs.hak5.org/hak5-usb-rubber-ducky/duckyscript-tm-quick-reference\">Hak5</a> to help users get started and make the most of this innovative technology. The github link for this project is:\n<a href=\"https://github.com/HenryHood2199/ZhuLi-HIDEMU\">GITHUB</a></div>\n<br>\n<div>This project is part of Henry Hood\'s final individual project for BSc Applied Computer Science at City College plymouth, in conjuction with University of Plymouth. Feel free to use any of this code for your own projects. \n</div>\n<br>\n<div>\nAuthors note: This entire project has involved research, testing, and a large amount of knowlege and skills that I have learnt from my 3 years at City College Plymouth, from embedded systems to object oriented programming, to web development(as you can tell this wasnt my strong suit), and I am extremely grateful for all my lecturers and peers have taught me over the years. \n</div>\n</div>\n</body>";
String indexSite = "<!DOCTYPE html>\n<html lang=\"en-GB\">\n<head>\n<meta charset=\"UTF-8\">\n<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n<style>\n*{\nmargin: 0;\npadding: 0;\n/*This got rid of that weird border in the top*/\n}\n@media  (min-aspect-ratio:1/1){\n*{\nmargin: 0;\npadding: 0;\nborder: 0;\n/*This got rid of that weird border in the top left*/\n}\n.header{\nfont: 2vw Arial;\nfont-weight: bold;\nmargin-left: 2vw;\n}\n.logs{\nwidth: 90vw;\nmargin: 5vw;\nfont: 2vw arial;\n}\n.playContainer{\nmargin-left: 4.5vw;\nmargin-top: 2vw;\n}\n.Play{\nborder-style: solid;\nborder-width: 4vw;\nborder-color: #202020;\nbox-sizing: border-box;\nwidth: 8vw;\nheight: 8vw;\nborder-width: 4vw 0px 4vw 8vw; \nborder-color: transparent  transparent  transparent  #202020;\n}\n.mnavbar{\ndisplay: none;\n}\n.navbar{\ndisplay: grid;\ngrid-template-columns: 10vw 20vw 20vw 20vw 20vw 10vw;\ngrid-template-rows:4vw;\nbackground-color: #028EE6;\nborder-style: solid;\nborder-color: black;\nborder-width: 1px;\nwidth: 100vw;\ntext-align: center;\n}\n.formclass{\ndisplay: grid;\ngrid-template-columns: 25vw 25vw 25vw 25vw;\ngrid-template-rows: 50vw;\n}\n.textInput{\nborder-style: solid;\nborder-color: black;\nborder-width: 4px;\nwidth: 15vw;\nheight: 13vw;\nmargin: 5vw;\nfont: 1vw Arial;\nwhite-space: nowrap;\n}\n.buttonDiv{\npadding-left: 5vw;\n}\n.subButton{\nwidth: 16vw;\nheight: 7vw;\nfont: 4vw Arial;\n}\n.Script{\nborder-radius: 25px;\ndisplay: block;\nborder-style: solid;\nborder-color: black;\nborder-width: 4px;\ntext-align: center;\nbackground-color: #028EE6;\nfont-family: Arial, Helvetica, sans-serif;\nfont: 2vw Arial;\ncolor: black;\nfont-weight: bold;\ntext-decoration: none;\nmargin: auto;\nfloat: left;\nheight: 16vw;\nwidth: 16vw;\nmargin: 4vw;\n} \n.Menu{\ndisplay: block;\nborder-style: solid;\nborder-color: black;\nborder-width: 1px;\ntext-align: center;\nfont-family: Arial, Helvetica, sans-serif;\nfont: 2vw Arial;\ncolor: black;\nfont-weight: bold;\ntext-decoration: none;\n}\n}\n/*  Media query for mobile devices. If device screen width is smaller than height then gets treated as mobile device*/\n@media  (max-aspect-ratio:1/1){\n*{\nbox-sizing: border-box;\n}\n.header{\nfont: 10vw Arial;\nfont-weight: bold;\nmargin-left: 2vw;\n}\n.logs{\nwidth: 90vw;\nmargin: 5vw;\nfont: 5vw arial;\n}\n.formclass{\ndisplay: grid;\ngrid-template-columns: 50vw 50vw;\ngrid-template-rows: 50vw 50vw;\n}\n.textInput{\nborder-style: solid;\nborder-color: black;\nborder-width: 4px;\nwidth: 40vw;\nheight: 30vw;\nmargin: 5vw;\nfont: 2vw Arial;\nwhite-space: nowrap;\n}\n.buttonDiv{\npadding-left: 18vw;\n}\n.subButton{\nwidth: 14vw;\nheight: 7vw;\nfont: 4vw Arial;\n}\n.blank{display: none;}\n.buttondiv{\ndisplay: grid;\ngrid-template-columns: 40vw 40vw;\ngrid-template-rows: 40vw 40vw;\n}\n.Script{\nborder-radius: 25px;\ndisplay: block;\nborder-style: solid;\nborder-color: black;\nborder-width: 4px;\ntext-align: center;\nbackground-color: #028EE6;\nfont-family: Arial, Helvetica, sans-serif;\nfont: 4vw Arial;\ncolor: black;\nfont-weight: bold;\ntext-decoration: none;\nmargin: auto;\nfloat: left;\nheight: 36vw;\nwidth: 36vw;\nmargin: 10vw;\npadding-top: 4vw;\n} \n.playContainer{\nmargin-left: 10vw;\nmargin-top: 5vw;\n}\n.Play{\nborder-style: solid;\nborder-width: 8vw;\nborder-color: #202020;\nbox-sizing: border-box;\nwidth: 16vw;\nheight: 16vw;\nborder-width: 8vw 0px 8vw 16vw; \nborder-color: transparent  transparent  transparent  #202020;\n}\n.Titlebar{\nwidth: 100%;\nfloat: inline-start;\nbackground-color: #028EE6;\n}\n.navbar\n{\ndisplay: none;\n}\n.mnavbar{\nbackground-color: #028EE6;\ntext-align: center;\nfont-family: Arial, Helvetica, sans-serif;\nfont: 7vw Arial;\ntext-decoration: none;\nborder-radius: 25px;\nborder-style: solid;\nborder-color: black;\nborder-width: 4px;\n}\n.DDopen{\ndisplay: block;\ntext-decoration: none;\ncolor: black;\nfont-weight: bold;\n}\n.MMenu{\nwidth: 100%;\ndisplay: block;\nborder-style: solid;\ntext-decoration: none;\ncolor: black;\nborder-width: 4px;\nborder-color: black transparent  black transparent;\n}    \n#myDropdown{\ndisplay: none;\n}\n}\n}\n</style>\n<script>\nfunction SHDD(){\ntry{\n//alert(\"test\");//debug test\nvar x = document.getElementById(\"myDropdown\");//passes dom element into variables\n//if dropdown display is block change it to none, else change it to block\nif (x.style.display == \"block\"){\nx.style.display = \"none\";\n}\nelse{\nx.style.display = \"block\";\n}\n}\ncatch(error){\nconsole.error(\"DropDown error: \"+error);\n}\n}\n</script>\n</head>\n<body>\n<div class=\"mobile-container\">\n<div class=\"Titlebar\">\n<a href=\"index.html\"></a>\n</div>\n<div class=\"mnavbar\">\n<a href=\"javascript:void(0);\" class=\"DDopen\" onclick=\"SHDD()\">\nMenu\n</a>\n<div id=\"myDropdown\">\n<a href=\"/index.html\" class=\"MMenu\">Main</a>\n<a href=\"/Edit.html\" class=\"MMenu\">Edit</a>\n<a href=\"/Logs.html\" class=\"MMenu\">Logs</a>\n<a href=\"/About.html\" class=\"MMenu\">About</a>\n<a href=\"javascript:void(0);\" class=\"DDopen\" onclick=\"SHDD()\">Close</a>\n</div>\n</div>\n</div>\n<div class=\"navbar\">\n<div></div>\n<a href=\"/index.html\" class=\"Menu\">Main</a>\n<a href=\"/Edit.html\" class=\"Menu\">Edit</a>\n<a href=\"/Logs.html\" class=\"Menu\">Logs</a>\n<a href=\"/About.html\" class=\"Menu\">About</a>\n<div></div>\n</div>\n<div></div>\n<div class=\"buttondiv\">\n<a href=\"/index.html?run1\" class=\"Script\">Saved1<div class=\"playContainer\"> <div class=\"Play\"></div></div></a>\n<a href=\"/index.html?run2\" class=\"Script\">Saved1<div class=\"playContainer\"> <div class=\"Play\"></div></div></a>\n<a href=\"/index.html?run3\" class=\"Script\">Saved1<div class=\"playContainer\"> <div class=\"Play\"></div></div></a>\n<a href=\"/index.html?run4\" class=\"Script\">Saved1<div class=\"playContainer\"> <div class=\"Play\"></div></div></a>\n</div>\n</body>";
String startupSite = "<!DOCTYPE html>\n<html lang=\"en-GB\">\n<head>\n<meta charset=\"UTF-8\">\n<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n<style>\n*{\nmargin: 0;\npadding: 0;\n/*This got rid of that weird border in the top*/\n}\n@media  (min-aspect-ratio:1/1){\n*{\nmargin: 0;\npadding: 0;\nborder: 0;\n/*This got rid of that weird border in the top left*/\n}\n.infotext{\nmargin-left: 2vw;\nfont: 1.5vw arial;\n}\n.Check123{\nmargin-left: 2vw;\nheight: 2vw;\nwidth: 2vw;\n}\n.header{\nfont: 2vw Arial;\nfont-weight: bold;\nmargin-left: 2vw;\n}\n.mnavbar{\ndisplay: none;\n}\n.navbar{\ndisplay: grid;\ngrid-template-columns: 10vw 80vw 10vw;\ngrid-template-rows:4vw;\nbackground-color: #028EE6;\nborder-style: solid;\nborder-color: black;\nborder-width: 1px;\nwidth: 100vw;\ntext-align: center;\n}\n.Menu{\ndisplay: block;\nborder-style: solid;\nborder-color: black;\nborder-width: 1px;\ntext-align: center;\nfont-family: Arial, Helvetica, sans-serif;\nfont: 2vw Arial;\ncolor: black;\nfont-weight: bold;\ntext-decoration: none;\n}\n.mainBody{\ndisplay: block;\nmargin: 12vw;\nbackground-color: white;\nwidth: 87vw;\ntext-align: center;\n}\n.textInput{\nborder-style: solid;\nborder-color: black;\nborder-width: 4px;\nwidth: 30vw;\nheight: 3vw;\nmargin: 3vw;\nfont: 2vw Arial;\nwhite-space: nowrap;\n}\n.buttonDiv{\npadding-left: 5vw;\n}\n.subButton{\nwidth: 16vw;\nheight: 7vw;\nfont: 4vw Arial;\n}\n.Footer\n{\ndisplay: grid;\ngrid-template-columns: 40vw 20vw 20vw 20vw;\nbackground-color: #028EE6;\nborder-style: solid;\nborder-color: black;\nborder-width: 1px;\n}\n.FooterItem{\ntext-align: center;\nfont-family: Arial, Helvetica, sans-serif;\nfont: 1vw Arial;\ntext-decoration: none;\ncolor: white;\nmargin-top: 2.5vh;\nmargin-bottom: 2.5vh;\ndisplay: block;\nfont-weight: bold;\n}\n}\n/*  Media query for mobile devices. If device screen width is smaller than height then gets treated as mobile device*/\n@media  (max-aspect-ratio:1/1){\n*{\nbox-sizing: border-box;\n}\n.header{\nfont: 10vw Arial;\nfont-weight: bold;\nmargin-left: 2vw;\n}\n.infotext{\nmargin-left: 5vw;\nfont: 6vw arial;\n}\n.Check123{\nmargin-left: 5vw;\nheight: 10vw;\nwidth: 10vw;\n}\n.formclass{\ndisplay: grid;\ngrid-template-columns: 90vw;\ngrid-template-rows: 50vw 50vw;\n}\n.textInput{\nborder-style: solid;\nborder-color: black;\nborder-width: 4px;\nwidth: 80vw;\nheight: 10vw;\nmargin: 5vw;\nfont: 5vw Arial;\nwhite-space: nowrap;\n}\n.buttonDiv{\npadding-left: 5vw;\n}\n.subButton{\nwidth: 50vw;\nheight: 15vw;\nfont: 10vw Arial;\n}\n.buttondiv{\ndisplay: grid;\ngrid-template-columns: 40vw 40vw;\ngrid-template-rows: 40vw 40vw;\n}\n.navbar\n{\ndisplay: none;\n}\n.mnavbar{\nbackground-color: #028EE6;\ntext-align: center;\nfont-family: Arial, Helvetica, sans-serif;\nfont: 7vw Arial;\ntext-decoration: none;\nborder-radius: 25px;\nborder-style: solid;\nborder-color: black;\nborder-width: 4px;\n}\n.DDopen{\ndisplay: block;\ntext-decoration: none;\ncolor: black;\nfont-weight: bold;\n}\n.MMenu{\nwidth: 100%;\ndisplay: block;\nborder-style: solid;\ntext-decoration: none;\ncolor: black;\nborder-width: 4px;\nborder-color: black transparent  black transparent;\n}\n#myDropdown{\ndisplay: none;\nwidth: 100%;\n}\n.Footer{\ndisplay: block;\nwidth: 100vw;\nheight: auto;\nbackground-color:   #028EE6 ;\ndisplay: grid;\ngrid-template-columns: 50% 50%;\n}\n.FooterItem{\ntext-align: center;\nfont-family: Arial, Helvetica, sans-serif;\nfont: 5vw Arial;\ntext-decoration: none;\ncolor: white;\nmargin-top: 2.5vh;\nmargin-bottom: 2.5vh;\ndisplay: block;\nfont-weight: bold;\n}\n}\n</style>\n</head>\n<body>\n<div class=\"mobile-container\">\n<div class=\"Titlebar\">\n<a href=\"index.html\"></a>\n</div>\n<div class=\"mnavbar\">\n<a>\nStartup\n</a>\n<div id=\"myDropdown\">\n</div>\n</div>\n</div>\n<div class=\"navbar\">\n<div></div>\n<a class=\"Menu\">Startup</a>\n<div></div>\n</div>\n<div></div>\n<div class=\"formclass\">\n<form method=\'POST\' action=\'/Edit.html?edit1\' >\n<h1 class=\"header\">SSID:</h1>\n<input name=\'SSID\' class=\"textInput\" type=\"text\" value=\"SSID\" />\n<br>\n<h1 class=\"header\">Password:</h1>\n<input name=\'Password\' class=\"textInput\" type=\"Password\" value=\"Password\"/>\n<br>\n<div class=\"buttonDiv\"> <input type=\'submit\' value=\'Submit\' class=\"subButton\"></div></form>\n</div>\n</body>";



String logSiteBegin = "<!DOCTYPE html>\n<html lang=\"en-GB\">\n<head>\n<style>\n*{\nmargin: 0;\npadding: 0;\n/*This got rid of that weird border in the top*/\n}\n@media  (min-aspect-ratio:1/1){\n*{\nmargin: 0;\npadding: 0;\nborder: 0;\n/*This got rid of that weird border in the top left*/\n}\n.header{\nfont: 2vw Arial;\nfont-weight: bold;\nmargin-left: 2vw;\n}\n.logs{\nwidth: 90vw;\nmargin: 5vw;\nfont: 2vw arial;\n}\n.playContainer{\nmargin-left: 4.5vw;\nmargin-top: 2vw;\n}\n.Play{\nborder-style: solid;\nborder-width: 4vw;\nborder-color: #202020;\nbox-sizing: border-box;\nwidth: 8vw;\nheight: 8vw;\nborder-width: 4vw 0px 4vw 8vw; \nborder-color: transparent  transparent  transparent  #202020;\n}\n.mnavbar{\ndisplay: none;\n}\n.navbar{\ndisplay: grid;\ngrid-template-columns: 10vw 20vw 20vw 20vw 20vw 10vw;\ngrid-template-rows:4vw;\nbackground-color: #028EE6;\nborder-style: solid;\nborder-color: black;\nborder-width: 1px;\nwidth: 100vw;\ntext-align: center;\n}\n.formclass{\ndisplay: grid;\ngrid-template-columns: 25vw 25vw 25vw 25vw;\ngrid-template-rows: 50vw;\n}\n.textInput{\nborder-style: solid;\nborder-color: black;\nborder-width: 4px;\nwidth: 15vw;\nheight: 13vw;\nmargin: 5vw;\nfont: 1vw Arial;\nwhite-space: nowrap;\n}\n.buttonDiv{\npadding-left: 5vw;\n}\n.subButton{\nwidth: 16vw;\nheight: 7vw;\nfont: 4vw Arial;\n}\n.Script{\nborder-radius: 25px;\ndisplay: block;\nborder-style: solid;\nborder-color: black;\nborder-width: 4px;\ntext-align: center;\nbackground-color: #028EE6;\nfont-family: Arial, Helvetica, sans-serif;\nfont: 2vw Arial;\ncolor: black;\nfont-weight: bold;\ntext-decoration: none;\nmargin: auto;\nfloat: left;\nheight: 16vw;\nwidth: 16vw;\nmargin: 4vw;\n} \n.Menu{\ndisplay: block;\nborder-style: solid;\nborder-color: black;\nborder-width: 1px;\ntext-align: center;\nfont-family: Arial, Helvetica, sans-serif;\nfont: 2vw Arial;\ncolor: black;\nfont-weight: bold;\ntext-decoration: none;\n}\n}\n/*  Media query for mobile devices. If device screen width is smaller than height then gets treated as mobile device*/\n@media  (max-aspect-ratio:1/1){\n*{\nbox-sizing: border-box;\n}\n.header{\nfont: 10vw Arial;\nfont-weight: bold;\nmargin-left: 2vw;\n}\n.logs{\nwidth: 90vw;\nmargin: 5vw;\nfont: 5vw arial;\n}\n.formclass{\ndisplay: grid;\ngrid-template-columns: 50vw 50vw;\ngrid-template-rows: 50vw 50vw;\n}\n.textInput{\nborder-style: solid;\nborder-color: black;\nborder-width: 4px;\nwidth: 40vw;\nheight: 30vw;\nmargin: 5vw;\nfont: 2vw Arial;\nwhite-space: nowrap;\n}\n.buttonDiv{\npadding-left: 18vw;\n}\n.subButton{\nwidth: 14vw;\nheight: 7vw;\nfont: 4vw Arial;\n}\n.blank{display: none;}\n.buttondiv{\ndisplay: grid;\ngrid-template-columns: 40vw 40vw;\ngrid-template-rows: 40vw 40vw;\n}\n.Script{\nborder-radius: 25px;\ndisplay: block;\nborder-style: solid;\nborder-color: black;\nborder-width: 4px;\ntext-align: center;\nbackground-color: #028EE6;\nfont-family: Arial, Helvetica, sans-serif;\nfont: 4vw Arial;\ncolor: black;\nfont-weight: bold;\ntext-decoration: none;\nmargin: auto;\nfloat: left;\nheight: 36vw;\nwidth: 36vw;\nmargin: 10vw;\npadding-top: 4vw;\n} \n.playContainer{\nmargin-left: 10vw;\nmargin-top: 5vw;\n}\n.Play{\nborder-style: solid;\nborder-width: 8vw;\nborder-color: #202020;\nbox-sizing: border-box;\nwidth: 16vw;\nheight: 16vw;\nborder-width: 8vw 0px 8vw 16vw; \nborder-color: transparent  transparent  transparent  #202020;\n}\n.Titlebar{\nwidth: 100%;\nfloat: inline-start;\nbackground-color: #028EE6;\n}\n.navbar\n{\ndisplay: none;\n}\n.mnavbar{\nbackground-color: #028EE6;\ntext-align: center;\nfont-family: Arial, Helvetica, sans-serif;\nfont: 7vw Arial;\ntext-decoration: none;\nborder-radius: 25px;\nborder-style: solid;\nborder-color: black;\nborder-width: 4px;\n}\n.DDopen{\ndisplay: block;\ntext-decoration: none;\ncolor: black;\nfont-weight: bold;\n}\n.MMenu{\nwidth: 100%;\ndisplay: block;\nborder-style: solid;\ntext-decoration: none;\ncolor: black;\nborder-width: 4px;\nborder-color: black transparent  black transparent;\n}\n#myDropdown{\ndisplay: none;\n}\n}\n</style>\n<meta charset=\"UTF-8\">\n<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n<script>\nfunction SHDD(){\ntry{\n//alert(\"test\");//debug test\nvar x = document.getElementById(\"myDropdown\");//passes dom element into variables\n//if dropdown display is block change it to none, else change it to block\nif (x.style.display == \"block\"){\nx.style.display = \"none\";\n}\nelse{\nx.style.display = \"block\";\n}\n}\ncatch(error){\nconsole.error(\"DropDown error: \"+error);\n}\n}\n</script>\n</head>\n<body >\n<div class=\"mobile-container\">\n<div class=\"Titlebar\">\n<a href=\"index.html\"></a>\n</div>\n<div class=\"mnavbar\">\n<a href=\"javascript:void(0);\" class=\"DDopen\" onclick=\"SHDD()\">\nMenu\n</a>\n<div id=\"myDropdown\">\n<a href=\"/index.html\" class=\"MMenu\">Main</a>\n<a href=\"/Edit.html\" class=\"MMenu\">Edit</a>\n<a href=\"/Logs.html\" class=\"MMenu\">Logs</a>\n<a href=\"/About.html\" class=\"MMenu\">About</a>\n<a href=\"javascript:void(0);\" class=\"DDopen\" onclick=\"SHDD()\">Close</a>\n</div>\n</div>\n</div>\n<div class=\"navbar\">\n<div></div>\n<a href=\"/index.html\" class=\"Menu\">Main</a>\n<a href=\"/Edit.html\" class=\"Menu\">Edit</a>\n<a href=\"/Logs.html\" class=\"Menu\">Logs</a>\n<a href=\"/About.html\" class=\"Menu\">About</a>\n<div></div>\n</div>\n<div></div>\n<div class=\"header\">\nLog:\n</div>\n<div class=\"logs\">\n";
String logSiteEnd="\n</div>\n</body>";