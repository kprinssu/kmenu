#include <psp2/ctrl.h>
#include <psp2/touch.h>
#include <psp2/moduleinfo.h>
#include <psp2/kernel/processmgr.h>

#include <string>
#include <cstdio>
#include <vita2d.h>

#include "../vitamenulib/libvitamenu/menu_manager.h"
#include "../vitamenulib/libvitamenu/menu.h"
#include "../vitamenulib/libvitamenu/menu_item.h"
#include "../vitamenulib/libvitamenu/utils.h"

#include "libUVL/libuvl.h"

PSP2_MODULE_INFO(0, 0, "kmenu");

void log(std::string s)
{
	printf("%s%s", s.c_str(), "\n");
}

void load_helloworld()
{	
	char test_homebrew_file[] = "cache0:/VitaDefilerClient/Documents/helloworld.elf";


	if(uvl_load(&test_homebrew_file[0]) < 0)
	{
		log("Hello world failed to load!");
	}
	else
	{
		log("Hello world loaded!");
	}
}

int main() {
	log("Starting");
	vita2d_init();

	char menu_name[] = "kMenu";
	char test_menuitem_name[] = "Run a test";

	char background_file[] = "cache0:/VitaDefilerClient/Documents/splash.png";

  	MenuManager * manager = new MenuManager();

	Menu * menu = new Menu(manager, 100, 50);
	menu->setName(&menu_name[0]);
	menu->setBackground(&background_file[0]);
	menu->addMenuItem(new MenuItem(&test_menuitem_name[0], 100, 100, &load_helloworld));

	//input for both touch and joysticks
	SceCtrlData pad;
	SceTouchData touch;

	while(1) {
		//read input
		sceCtrlPeekBufferPositive(0, &pad, 1);
		sceTouchPeek(0, &touch, 1);

		//quit when you press triangle
		if (pad.buttons & PSP2_CTRL_TRIANGLE)
		{
			break;
		}

		manager->handleDpad(&pad);

		manager->handleTouch(&touch);

		vita2d_start_drawing();
		vita2d_clear_screen();

		manager->draw();

		vita2d_end_drawing();
		vita2d_swap_buffers();
	}

	log("Stopped.\n");
	

	vita2d_fini();

	sceKernelExitProcess(0);
	delete manager;

	return 0;
}