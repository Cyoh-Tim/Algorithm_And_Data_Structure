/*********************************
File name: reference_for_menu_settings.c

Author: seuteut879@gmail.com

Description: Menu list for menu setting \
		Linked list for menu list \
		It is recommend to make interface function in MENU_ITEM
		to make function about MENU_LIST, would be used to all cairo weston code.

Others: 
**********************************/

#include <stdio.h>

#define MAKE_ENUM(VAR) VAR,
#define MAKE_STRINGS(VAR) #VAR,

// TBD : leftover menu items aren't yet made
#define MEMU_STR_ENUM(DO) \
	DO(MENU_STR_NONE) \
	DO(MENU_STR_TITLE_MAIN) \
	DO(MENU_STR_TITLE_SOUND) \
	DO(MENU_STR_TITLE_SPK) \
	DO(MENU_STR_TITLE_SYSTEM) \
\
	DO(MENU_STR_TITLE_BASE) \
	DO(MENU_STR_TITLE_TREBLE) \
	DO(MENU_STR_TITLE_DYNAM) \
\
	DO(MENU_STR_MAIN) \
	DO(MENU_STR_SOUND) \
	DO(MENU_STR_SPK) \
	DO(MENU_STR_SYSTEM) \
\
	DO(MENU_STR_SOUND_BASE) \
	DO(MENU_STR_SOUND_TREBLE) \
	DO(MENU_STR_SOUND_DYNAM) \
	DO(MENU_STR_SOUND_MODE) \
	DO(MENU_STR_SOUND_UPMIX) \
	DO(MENU_STR_SOUND_DRC) \
	DO(MENU_STR_SOUND_VIRTUAL) \
\
	DO(MENU_STR_NUM_P10) \
	DO(MENU_STR_NUM_P05) \
	DO(MENU_STR_NUM_P00) \
	DO(MENU_STR_NUM_M05) \
	DO(MENU_STR_NUM_M10) \
\
	DO(MENU_STR_ON) \
	DO(MENU_STR_OFF) \
\
	DO(MENU_STR_MAX)

typedef enum {
	MEMU_STR_ENUM(MAKE_ENUM)
} E_MEMU_STR;
const char* const menu_str_value[] = {
	MEMU_STR_ENUM(MAKE_STRINGS)
};

typedef struct _MEMU_ITEM {
	E_MEMU_STR title;
	E_MEMU_STR item;
	//	E_MEMU_STR info;

	struct _MEMU_ITEM* parent;
	struct _MEMU_ITEM* child_list;
	int child_index;
	int child_num;
} MEMU_ITEM, * PMEMU_ITEM, ** LPMEMU_ITEM;

MEMU_ITEM menu_base[];
MEMU_ITEM menu_treble[];
MEMU_ITEM menu_dynam[];
MEMU_ITEM menu_sound[];
MEMU_ITEM menu_main[];
MEMU_ITEM menu_head[];

MEMU_ITEM menu_base[] = {
	{MENU_STR_NONE, MENU_STR_NUM_P10, menu_sound, NULL, },
	{MENU_STR_NONE, MENU_STR_NUM_P05, menu_sound, NULL, },
	{MENU_STR_NONE, MENU_STR_NUM_P00, menu_sound, NULL, },
	{MENU_STR_NONE, MENU_STR_NUM_M05, menu_sound, NULL, },
	{MENU_STR_NONE, MENU_STR_NUM_M10, menu_sound, NULL, },

	{MENU_STR_NONE, MENU_STR_NONE, NULL, NULL, }
};

MEMU_ITEM menu_treble[] = {
	{MENU_STR_NONE, MENU_STR_NUM_P10, menu_sound, NULL, },
	{MENU_STR_NONE, MENU_STR_NUM_P05, menu_sound, NULL, },
	{MENU_STR_NONE, MENU_STR_NUM_P00, menu_sound, NULL, },
	{MENU_STR_NONE, MENU_STR_NUM_M05, menu_sound, NULL, },
	{MENU_STR_NONE, MENU_STR_NUM_M10, menu_sound, NULL, },

	{MENU_STR_NONE, MENU_STR_NONE, NULL, NULL, }
};

MEMU_ITEM menu_dynam[] = {
	{MENU_STR_NONE, MENU_STR_ON, menu_sound, NULL, },
	{MENU_STR_NONE, MENU_STR_OFF, menu_sound, NULL, },

	{MENU_STR_NONE, MENU_STR_NONE, NULL, NULL, }
};

MEMU_ITEM menu_sound[] = {
	{MENU_STR_TITLE_BASE, MENU_STR_SOUND_BASE, menu_main, menu_base, },
	{MENU_STR_TITLE_TREBLE, MENU_STR_SOUND_TREBLE, menu_main, menu_treble, },
	{MENU_STR_TITLE_DYNAM, MENU_STR_SOUND_DYNAM, menu_main, menu_dynam, },
	{MENU_STR_NONE, MENU_STR_NONE, NULL, NULL, }
};

MEMU_ITEM menu_main[] = {
	{MENU_STR_TITLE_SOUND, MENU_STR_SOUND, menu_head, menu_sound, },
	{MENU_STR_NONE, MENU_STR_SPK, menu_head, NULL, },
	{MENU_STR_NONE, MENU_STR_SYSTEM, menu_head, NULL, },
	{MENU_STR_NONE, MENU_STR_NONE, NULL, NULL, }
};

MEMU_ITEM menu_head[] = {
	{MENU_STR_TITLE_MAIN, MENU_STR_TITLE_MAIN, NULL, menu_main, },
	{MENU_STR_NONE, MENU_STR_NONE, NULL, NULL, }
};

// for 
void print_list(PMEMU_ITEM menu_list)
{
	PMEMU_ITEM child;
	if (menu_list == NULL) {
		return;
	}
	if (menu_list->child_list != NULL)
		printf("title<<<:%s\n", menu_str_value[menu_list->title]);
	child = menu_list->child_list;
	if (child == NULL) {
		return;
	}
	menu_list->child_num = 0;
	while (child->item != MENU_STR_NONE) {
		printf("item:%s\n", menu_str_value[child->item]);
		print_list(child);
		child++;
		menu_list->child_num++;
	}
	if (menu_list->child_list != NULL)
		printf("title:%s>>>[%d]\n", menu_str_value[menu_list->title], menu_list->child_num);
}
int main(int argc, char* argv[]) {
	print_list(&menu_head[0]);
	return 0;
}