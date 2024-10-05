#include "../tomb4/pch.h"
#include "input.h"
#include "dxshell.h"
#include "../game/sound.h"
#include "../game/newinv.h"
#include "../game/lara_states.h"
#include "../game/control.h"
#include "../game/camera.h"
#include "LoadSave.h"
#include "winmain.h"
#include "../game/lara.h"
#include "../game/savegame.h"
#include "../game/gameflow.h"
#include "../game/spotcam.h"
#include "../tomb4/tomb4.h"

const char* KeyboardButtons[272] =
{
	0,
	"Esc", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "+", "Bksp",
	"Tab", "q", "w", "e", "r", "t", "y", "u", "i", "o", "p", "<", ">", "Return",
	"Ctrl", "a", "s", "d", "f", "g", "h", "j", "k", "l", ";", "'", "`",
	"Shift", "#", "z", "x", "c", "v", "b", "n", "m", ",", ".", "/", "Shift",
	"Padx", "Alt", "Space", "Caps", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	"Nmlk", 0,
	"Pad7", "Pad8", "Pad9", "Pad-",
	"Pad4", "Pad5", "Pad6", "Pad+",
	"Pad1", "Pad2", "Pad3",
	"Pad0", "Pad.", 0, 0, "\\", 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	"Enter", "Ctrl", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	"Shift", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	"Pad/", 0, 0, "Alt", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	"Home", "Up", "PgUp", 0, "Left", 0, "Right", 0, "End", "Down", "PgDn", "Ins", "Del",
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	"Joy 1", "Joy 2", "Joy 3", "Joy 4", "Joy 5", "Joy 6", "Joy 7", "Joy 8",
	"Joy 9", "Joy 10", "Joy 11", "Joy 12", "Joy 13", "Joy 14", "Joy 15", "Joy 16"
};

const char* GermanKeyboard[272] =
{
	0,
	"Esc", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "=", "`", "Entf",
	"Tab", "Q", "W", "E", "R", "T", "Z", "U", "I", "O", "P", "~u", "x", "Enter",
	"Strg", "A", "S", "D", "F", "G", "H", "J", "K", "L", "~o", "~a", "( ",
	"Shift", "#", "Y", "X", "C", "V", "B", "N", "M", ",", ".", "-", "Shift",
	"Num x", "Alt", "Leert.", "Caps", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	"Nmlk", 0,
	"Num7", "Num8", "Num9", "Num-",
	"Num4", "Num5", "Num6", "Num+",
	"Num1", "Num2", "Num3",
	"Num0", "Num.", 0, 0, ">", 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	"Enter", "Strg", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	"Shift", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	"Num/", 0, 0, "Alt", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	"Pos1", "Hoch", "BdAuf", 0, "Links", 0, "Rechts", 0, "Ende", "Runter", "BdAb", "Einfg", "Entf",
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	"Joy 1", "Joy 2", "Joy 3", "Joy 4", "Joy 5", "Joy 6", "Joy 7", "Joy 8",
	"Joy 9", "Joy 10", "Joy 11", "Joy 12", "Joy 13", "Joy 14", "Joy 15", "Joy 16"
};

short layout[2][18] =
{
	{ DIK_UP, DIK_DOWN, DIK_LEFT, DIK_RIGHT, DIK_PERIOD, DIK_SLASH, DIK_RSHIFT, DIK_RALT, DIK_RCONTROL,
	DIK_SPACE, DIK_COMMA, DIK_NUMPAD0, DIK_END, DIK_ESCAPE, DIK_DELETE, DIK_PGDN, DIK_P, DIK_RETURN },

	{ DIK_UP, DIK_DOWN, DIK_LEFT, DIK_RIGHT, DIK_PERIOD, DIK_SLASH, DIK_RSHIFT, DIK_RALT, DIK_RCONTROL,
	DIK_SPACE, DIK_COMMA, DIK_NUMPAD0, DIK_END, DIK_ESCAPE, DIK_DELETE, DIK_PGDN, DIK_P, DIK_RETURN }
};

long conflict[18];
long input;
long linput;
long dbinput;
long inputBusy;
short ammo_change_timer = 0;
char ammo_change_buf[12];

static long joy_x;
static long joy_y;
static long joy_fire;

static void DoWeaponHotkey()	//adds extra checks and does ammo type swaps..
{
	short state;
	bool goin;

	if (!lara_item)
		goin = 0;
	else
	{
		state = lara_item->current_anim_state;
		goin = !(gfLevelFlags & GF_YOUNGLARA) && (lara.water_status == LW_ABOVE_WATER || lara.water_status == LW_WADE) && !bDisableLaraControl &&
			(state != AS_ALL4S && state != AS_CRAWL && state != AS_ALL4TURNL && state != AS_ALL4TURNR && state != AS_CRAWLBACK &&
				state != AS_CRAWL2HANG && state != AS_DUCK && state != AS_DUCKROTL && state != AS_DUCKROTR);
	}

	if (!goin)
		return;

	if (keymap[DIK_1])
	{
		if (!(lara.pistols_type_carried & W_PRESENT))
			return;

		lara.request_gun_type = WEAPON_PISTOLS;

		if (lara.gun_status == LG_NO_ARMS && lara.gun_type == WEAPON_PISTOLS)
			lara.gun_status = LG_DRAW_GUNS;
	}
	else if (keymap[DIK_2])
	{
		if (!(lara.shotgun_type_carried & W_PRESENT))
			return;

		lara.request_gun_type = WEAPON_SHOTGUN;

		if (lara.gun_type == WEAPON_SHOTGUN)
		{
			if (lara.gun_status == LG_NO_ARMS)
				lara.gun_status = LG_DRAW_GUNS;
			else if (lara.gun_status == LG_READY && !ammo_change_timer)
			{
				if (!tomb4.ammotype_hotkeys)
					return;

				memset(ammo_change_buf, 0, sizeof(ammo_change_buf));

				if (lara.shotgun_type_carried & W_AMMO2)
				{
					lara.shotgun_type_carried &= ~W_AMMO2;
					lara.shotgun_type_carried |= W_AMMO1;
					ammo_change_timer = 30;
					sprintf(ammo_change_buf, "Normal");
				}
				else if (lara.shotgun_type_carried & W_AMMO1)
				{
					lara.shotgun_type_carried &= ~W_AMMO1;
					lara.shotgun_type_carried |= W_AMMO2;
					ammo_change_timer = 30;
					sprintf(ammo_change_buf, "Wideshot");
				}
			}
		}
	}
	else if (keymap[DIK_3])
	{
		if (!(lara.uzis_type_carried & W_PRESENT))
			return;

		lara.request_gun_type = WEAPON_UZI;

		if (lara.gun_status == LG_NO_ARMS && lara.gun_type == WEAPON_UZI)
			lara.gun_status = LG_DRAW_GUNS;
	}
	else if (keymap[DIK_4])
	{
		if (!(lara.sixshooter_type_carried & W_PRESENT))
			return;

		lara.request_gun_type = WEAPON_REVOLVER;

		if (lara.gun_status == LG_NO_ARMS && lara.gun_type == WEAPON_REVOLVER)
			lara.gun_status = LG_DRAW_GUNS;
	}
	else if (keymap[DIK_5])
	{
		if (!(lara.grenade_type_carried & W_PRESENT))
			return;

		lara.request_gun_type = WEAPON_GRENADE;

		if (lara.gun_type == WEAPON_GRENADE)
		{
			if (lara.gun_status == LG_NO_ARMS)
				lara.gun_status = LG_DRAW_GUNS;
			else if (lara.gun_status == LG_READY && !ammo_change_timer)
			{
				if (!tomb4.ammotype_hotkeys)
					return;

				memset(ammo_change_buf, 0, sizeof(ammo_change_buf));

				if (lara.grenade_type_carried & W_AMMO3)
				{
					lara.grenade_type_carried &= ~W_AMMO3;
					lara.grenade_type_carried |= W_AMMO2;
					ammo_change_timer = 30;
					sprintf(ammo_change_buf, "Super");
				}
				else if (lara.grenade_type_carried & W_AMMO2)
				{
					lara.grenade_type_carried &= ~W_AMMO2;
					lara.grenade_type_carried |= W_AMMO1;
					ammo_change_timer = 30;
					sprintf(ammo_change_buf, "Normal");
				}
				else if (lara.grenade_type_carried & W_AMMO1)
				{
					lara.grenade_type_carried &= ~W_AMMO1;
					lara.grenade_type_carried |= W_AMMO3;
					ammo_change_timer = 30;
					sprintf(ammo_change_buf, "Flash");
				}
			}
		}
	}
	else if (keymap[DIK_6])
	{
		if (!(lara.crossbow_type_carried & W_PRESENT))
			return;

		lara.request_gun_type = WEAPON_CROSSBOW;

		if (lara.gun_type == WEAPON_CROSSBOW)
		{
			if (lara.gun_status == LG_NO_ARMS)
				lara.gun_status = LG_DRAW_GUNS;
			else if (lara.gun_status == LG_READY && !ammo_change_timer)
			{
				if (!tomb4.ammotype_hotkeys)
					return;

				memset(ammo_change_buf, 0, sizeof(ammo_change_buf));

				if (lara.crossbow_type_carried & W_AMMO3)
				{
					lara.crossbow_type_carried &= ~W_AMMO3;
					lara.crossbow_type_carried |= W_AMMO2;
					ammo_change_timer = 30;
					sprintf(ammo_change_buf, "Poison");
				}
				else if (lara.crossbow_type_carried & W_AMMO2)
				{
					lara.crossbow_type_carried &= ~W_AMMO2;
					lara.crossbow_type_carried |= W_AMMO1;
					ammo_change_timer = 30;
					sprintf(ammo_change_buf, "Normal");
				}
				else if (lara.crossbow_type_carried & W_AMMO1)
				{
					lara.crossbow_type_carried &= ~W_AMMO1;
					lara.crossbow_type_carried |= W_AMMO3;
					ammo_change_timer = 30;
					sprintf(ammo_change_buf, "Explosive");
				}
			}
		}
	}
}

long Key(long number)
{
	short key;

	key = layout[1][number];

	if (key < 256)
	{
		if (keymap[key])
			return 1;

		switch (key)
		{
		case DIK_RCONTROL:
			return keymap[DIK_LCONTROL];

		case DIK_LCONTROL:
			return keymap[DIK_RCONTROL];

		case DIK_RSHIFT:
			return keymap[DIK_LSHIFT];

		case DIK_LSHIFT:
			return keymap[DIK_RSHIFT];

		case DIK_RMENU:
			return keymap[DIK_LMENU];

		case DIK_LMENU:
			return keymap[DIK_RMENU];
		}
	}
	else if (joy_fire & (1 << key))
		return 1;

	if (conflict[number])
		return 0;

	key = layout[0][number];

	if (keymap[key])
		return 1;

	switch (key)
	{
	case DIK_RCONTROL:
		return keymap[DIK_LCONTROL];

	case DIK_LCONTROL:
		return keymap[DIK_RCONTROL];

	case DIK_RSHIFT:
		return keymap[DIK_LSHIFT];

	case DIK_LSHIFT:
		return keymap[DIK_RSHIFT];

	case DIK_RMENU:
		return keymap[DIK_LMENU];

	case DIK_LMENU:
		return keymap[DIK_RMENU];
	}

	return 0;
}

bool xinput_devices[4];
gamepad_t gamepads[4];
static void gamepad_update_key(gamepad_t* pad, uint8_t button_name, uint32_t pressed) {
	uint32_t was_pressed = pad->buttons[button_name] & gamepad_key_flag_pressed;
	uint8_t result = pressed ? gamepad_key_flag_pressed : gamepad_key_flag_none;
	result |= (pressed && !was_pressed) ? gamepad_key_flag_just_pressed : gamepad_key_flag_none;
	result |= (!pressed && was_pressed) ? gamepad_key_flag_just_released : gamepad_key_flag_none;
	pad->buttons[button_name] = result;
}
static uint32_t gamepad_is_pressed(gamepad_t* pad, gamepad_button_t button_name) {
	uint32_t result = pad && (pad->buttons[button_name] & gamepad_key_flag_pressed);
	return result;
}
static uint32_t gamepad_just_pressed(gamepad_t* pad, gamepad_button_t button_name) {
	uint32_t result = pad && (pad->buttons[button_name] & gamepad_key_flag_just_pressed);
	return result;
}
static uint32_t gamepad_just_released(gamepad_t* pad, gamepad_button_t button_name) {
	uint32_t result = pad && (pad->buttons[button_name] & gamepad_key_flag_just_released);
	return result;
}
static bool xinput_update() {
	bool result = true;
	bool check_for_new_controller = false;
	static uint64_t frequency = 0;
	static uint64_t previous_time = 0;
	if (!frequency) {
		QueryPerformanceFrequency((LARGE_INTEGER*)&frequency);
	}
	uint64_t time;
	QueryPerformanceCounter((LARGE_INTEGER*)&time);
	if (previous_time == 0) {
		check_for_new_controller = true;
		previous_time = time;
	}
	else {
		float delta = (float)((double)(time - previous_time) / (double)frequency);
		if (delta >= 3.0f) {
			check_for_new_controller = true;
			previous_time = time;
		}
	}
	for (uint32_t i = 0; i < 4; i++) {
		if (xinput_devices[i] || check_for_new_controller) {
			XINPUT_STATE pad_state;
			DWORD result = XInputGetState(i, &pad_state);
			if (result == ERROR_SUCCESS) {
				xinput_devices[i] = true;
				gamepad_t* pad = gamepads + i;
				gamepad_update_key(pad, gamepad_button_menu, pad_state.Gamepad.wButtons & XINPUT_GAMEPAD_START);
				gamepad_update_key(pad, gamepad_button_view, pad_state.Gamepad.wButtons & XINPUT_GAMEPAD_BACK);
				gamepad_update_key(pad, gamepad_button_a, pad_state.Gamepad.wButtons & XINPUT_GAMEPAD_A);
				gamepad_update_key(pad, gamepad_button_b, pad_state.Gamepad.wButtons & XINPUT_GAMEPAD_B);
				gamepad_update_key(pad, gamepad_button_x, pad_state.Gamepad.wButtons & XINPUT_GAMEPAD_X);
				gamepad_update_key(pad, gamepad_button_y, pad_state.Gamepad.wButtons & XINPUT_GAMEPAD_Y);
				gamepad_update_key(pad, gamepad_button_dpad_up, pad_state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP);
				gamepad_update_key(pad, gamepad_button_dpad_down, pad_state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN);
				gamepad_update_key(pad, gamepad_button_dpad_left, pad_state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT);
				gamepad_update_key(pad, gamepad_button_dpad_right, pad_state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT);
				gamepad_update_key(pad, gamepad_button_left_shoulder, pad_state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER);
				gamepad_update_key(pad, gamepad_button_right_shoulder, pad_state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER);
				gamepad_update_key(pad, gamepad_button_left_thumbstick, pad_state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_THUMB);
				gamepad_update_key(pad, gamepad_button_right_thumbstick, pad_state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_THUMB);
				pad->left_trigger = pad_state.Gamepad.bLeftTrigger / 255.0f;
				pad->right_trigger = pad_state.Gamepad.bRightTrigger / 255.0f;
				{
					float x = ((float)pad_state.Gamepad.sThumbLX) + 32768;
					float y = ((float)pad_state.Gamepad.sThumbLY) + 32768;
					x = (x / 65535) * 2 - 1;
					y = (y / 65535) * 2 - 1;
					float magnitude = sqrtf((x * x) + (y * y));
					if (magnitude) {
						x /= magnitude;
						y /= magnitude;
						magnitude = (magnitude < 0) ? 0 : ((magnitude > 1) ? 1 : magnitude);
						pad->left_thumbstick_x = x * magnitude;
						pad->left_thumbstick_y = y * magnitude;
					}
					else {
						pad->left_thumbstick_x = 0;
						pad->left_thumbstick_y = 0;
					}
				}
				{
					float x = ((float)pad_state.Gamepad.sThumbRX) + 32768;
					float y = ((float)pad_state.Gamepad.sThumbRY) + 32768;
					x = (x / 65535) * 2 - 1;
					y = (y / 65535) * 2 - 1;
					float magnitude = sqrtf((x * x) + (y * y));
					if (magnitude) {
						x /= magnitude;
						y /= magnitude;
						magnitude = (magnitude < 0) ? 0 : ((magnitude > 1) ? 1 : magnitude);
						pad->right_thumbstick_x = x * magnitude;
						pad->right_thumbstick_y = y * magnitude;
					}
					else {
						pad->right_thumbstick_x = 0;
						pad->right_thumbstick_y = 0;
					}
				}
			}
			else if (result == ERROR_DEVICE_NOT_CONNECTED) {
				xinput_devices[i] = false;
				gamepad_t* pad = gamepads + i;
				memset(pad, 0, sizeof(gamepad_t));
			}
			else {

				xinput_devices[i] = false;
				gamepad_t* pad = gamepads + i;
				memset(pad, 0, sizeof(gamepad_t));
				result = false;
			}
		}
	}
	return result;
}

long S_UpdateInput()
{
	static long LookCnt;
	static long med_hotkey_timer;
	short state;
	static bool flare_no_db = 0;
	bool debounce;

	debounce = SetDebounce;
	DXReadKeyboard(keymap);
#if 0
	if (ControlMethod == 1)
		joy_fire = ReadJoystick(joy_x, joy_y);
#else
	xinput_update();
	gamepad_t* pad = 0;
	for (uint32_t i = 0; i < 4; i++) {
		if (xinput_devices[i] == true) {
			pad = gamepads + i;
			break;
		}
	}
#endif

	linput = 0;

#if 0
	if (ControlMethod == 1)
	{
		if (joy_x < -8)
			linput = IN_LEFT;
		else if (joy_x > 8)
			linput = IN_RIGHT;

		if (joy_y > 8)
			linput |= IN_BACK;
		else if (joy_y < -8)
			linput |= IN_FORWARD;
	}
#endif

	if (Key(0))
		linput |= IN_FORWARD;

	if (pad && (gamepad_is_pressed(pad, gamepad_button_dpad_up) || pad->left_thumbstick_y > 0.25f)) {
		linput |= IN_FORWARD;
	}

	if (Key(1))
		linput |= IN_BACK;

	if (pad && (gamepad_is_pressed(pad, gamepad_button_dpad_down) || pad->left_thumbstick_y < -0.25f)) {
		linput |= IN_BACK;
	}

	if (Key(2))
		linput |= IN_LEFT;

	if (pad && (gamepad_is_pressed(pad, gamepad_button_dpad_left) || pad->left_thumbstick_x < -0.25f)) {
		linput |= IN_LEFT;
	}

	if (Key(3))
		linput |= IN_RIGHT;

	if (pad && (gamepad_is_pressed(pad, gamepad_button_dpad_right) || pad->left_thumbstick_x > 0.25f)) {
		linput |= IN_RIGHT;
	}

	if (Key(4))
		linput |= IN_DUCK;

	if (pad && pad->left_trigger > 0.25f) {
		linput |= IN_DUCK;
	}

	if (Key(5))
		linput |= IN_SPRINT;

	if (pad && pad->right_trigger > 0.25f) {
		linput |= IN_SPRINT;
	}

	if (Key(6))
		linput |= IN_WALK;

	if (pad && gamepad_is_pressed(pad, gamepad_button_right_shoulder)) {
		linput |= IN_WALK;
	}

	if (Key(7))
		linput |= IN_JUMP;

	if (pad && gamepad_is_pressed(pad, gamepad_button_x)) {
		linput |= IN_JUMP;
	}

	if (Key(8))
		linput |= IN_SELECT | IN_ACTION;

	if (pad && gamepad_is_pressed(pad, gamepad_button_a)) {
		linput |= IN_SELECT | IN_ACTION;
	}

	if (Key(9))
		linput |= IN_DRAW;

	if (pad && gamepad_is_pressed(pad, gamepad_button_y)) {
		linput |= IN_DRAW;
	}

	bool flare_pressed = Key(10);
	flare_pressed = flare_pressed || ( pad && gamepad_is_pressed(pad, gamepad_button_right_thumbstick) );

	if (flare_pressed)
	{
		if (!flare_no_db)
		{
			state = lara_item->current_anim_state;

			if (state == AS_ALL4S || state == AS_CRAWL || state == AS_ALL4TURNL ||
				state == AS_ALL4TURNR || state == AS_CRAWLBACK || state == AS_CRAWL2HANG)
			{
				SoundEffect(SFX_LARA_NO, 0, SFX_ALWAYS);
				flare_no_db = 1;
			}
			else
			{
				flare_no_db = 0;
				linput |= IN_FLARE;
			}
		}
	}
	else
		flare_no_db = 0;

	if (Key(11))
		linput |= IN_LOOK;


	if (pad && gamepad_is_pressed(pad, gamepad_button_left_shoulder)) {
		linput |= IN_LOOK;
	}

	if (Key(12))
		linput |= IN_ROLL;

	if (pad && gamepad_is_pressed(pad, gamepad_button_b)) {
		linput |= IN_ROLL;
	}

	if (Key(13))
		linput |= IN_OPTION;

	if (pad && gamepad_is_pressed(pad, gamepad_button_view)) {
		linput |= IN_OPTION;
	}

	if (Key(14))
		linput |= IN_WALK | IN_LEFT;

	if (Key(15))
		linput |= IN_WALK | IN_RIGHT;

	if (Key(16))
		linput |= IN_PAUSE;

	if (pad && gamepad_is_pressed(pad, gamepad_button_menu)) {
		linput |= IN_PAUSE;
	}

	if (Key(17))
		linput |= IN_SELECT;

	if (keymap[DIK_ESCAPE])
		linput |= IN_DESELECT | IN_OPTION;

	if (pad && gamepad_is_pressed(pad, gamepad_button_view)) {
		linput |= IN_DESELECT | IN_OPTION;
	}

	if (lara.gun_status == LG_READY)
	{
		savegame.AutoTarget = (uchar)App.AutoTarget;

		if (linput & IN_LOOK)
		{
			if (LookCnt >= 6)
				LookCnt = 100;
			else
			{
				linput &= ~IN_LOOK;
				LookCnt++;
			}
		}
		else
		{
			if (LookCnt && LookCnt != 100)
				linput |= IN_TARGET;

			LookCnt = 0;
		}
	}

	DoWeaponHotkey();

	if (keymap[DIK_0])
	{
		if (!med_hotkey_timer)
		{
			if (lara_item->hit_points > 0 && lara_item->hit_points < 1000 || lara.poisoned)
			{
				if (lara.num_small_medipack)
				{
					if (lara.num_small_medipack != -1)
						lara.num_small_medipack--;

					lara.dpoisoned = 0;
					lara_item->hit_points += 500;
					SoundEffect(SFX_MENU_MEDI, 0, SFX_ALWAYS);
					savegame.Game.HealthUsed++;

					if (lara_item->hit_points > 1000)
						lara_item->hit_points = 1000;

					if (InventoryActive && !lara.num_small_medipack)
					{
						construct_object_list();

						if (lara.num_large_medipack)
							setup_objectlist_startposition(INV_BIGMEDI_ITEM);
						else
							setup_objectlist_startposition(INV_MEMCARD_LOAD_ITEM);
					}

					med_hotkey_timer = 15;
				}
			}
		}
	}
	else if (keymap[DIK_9])
	{
		if (!med_hotkey_timer)
		{
			if (lara_item->hit_points > 0 && lara_item->hit_points < 1000 || lara.poisoned)
			{
				if (lara.num_large_medipack)
				{
					if (lara.num_large_medipack != -1)
						lara.num_large_medipack--;

					lara.dpoisoned = 0;
					lara_item->hit_points = 1000;
					SoundEffect(SFX_MENU_MEDI, 0, SFX_ALWAYS);
					savegame.Game.HealthUsed++;
					med_hotkey_timer = 15;

					if (InventoryActive && !lara.num_large_medipack)
					{
						construct_object_list();

						if (lara.num_small_medipack)
							setup_objectlist_startposition(INV_SMALLMEDI_ITEM);
						else
							setup_objectlist_startposition(INV_MEMCARD_LOAD_ITEM);
					}
				}
			}
		}
	}
	else if (med_hotkey_timer)
		med_hotkey_timer--;

	if (linput & IN_WALK && !(linput & (IN_FORWARD | IN_BACK)))
	{
		if (linput & IN_LEFT)
			linput = (linput & ~IN_LEFT) | IN_LSTEP;
		else if (linput & IN_RIGHT)
			linput = (linput & ~IN_RIGHT) | IN_RSTEP;
	}

	if (linput & IN_FORWARD && linput & IN_BACK)
		linput |= IN_ROLL;

	if (linput & IN_ROLL && BinocularRange)
		linput &= ~IN_ROLL;

	if ((linput & (IN_RIGHT | IN_LEFT)) == (IN_RIGHT | IN_LEFT))
		linput -= IN_RIGHT | IN_LEFT;

	if (debounce)
		dbinput = inputBusy;

	if (!gfGameMode && Gameflow->LoadSaveEnabled)
	{
		if (keymap[DIK_F5])
			linput |= IN_SAVE;

		if (keymap[DIK_F6])
			linput |= IN_LOAD;
	}

	if (keymap[DIK_APOSTROPHE])
		DXSaveScreen(App.dx.lpBackBuffer, "Tomb");

	inputBusy = linput;

	if (lara.Busy)
	{
		linput &= IN_PAUSE | IN_LOOK | IN_OPTION | IN_RIGHT | IN_LEFT | IN_BACK | IN_FORWARD;

		if (linput & IN_FORWARD && linput & IN_BACK)
			linput ^= IN_BACK;
	}

	if (debounce)
		dbinput = inputBusy & (dbinput ^ inputBusy);

	input = linput;
	return 1;
}

long ReadJoystick(long& x, long& y)
{
	JOYINFOEX joystick;
	static JOYCAPS caps;
	static long unavailable = 1;

	joystick.dwSize = sizeof(JOYINFOEX);
	joystick.dwFlags = JOY_RETURNX | JOY_RETURNY | JOY_RETURNBUTTONS;

	if (joyGetPosEx(0, &joystick) != JOYERR_NOERROR)
	{
		unavailable = 1;
		x = 0;
		y = 0;
		return 0;
	}

	if (unavailable)
	{
		if (joyGetDevCaps(JOYSTICKID1, &caps, sizeof(caps)) != JOYERR_NOERROR)
		{
			x = 0;
			y = 0;
			return 0;
		}
		else
			unavailable = 0;
	}

	x = (joystick.dwXpos << 5) / (caps.wXmax - caps.wXmin) - 16;
	y = (joystick.dwYpos << 5) / (caps.wYmax - caps.wYmin) - 16;
	return joystick.dwButtons;
}
