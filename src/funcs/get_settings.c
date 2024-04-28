/*
** EPITECH PROJECT, 2024
** settings
** File description:
** RPG
*/

#include "lib.h"
#include "settings/settings.h"

static display_t get_display(const char **file)
{
    display_t display = {0};

    display.resolution.y = get_idata("iScreenHeight", file);
    display.resolution.x = get_idata("iScreenWidth", file);
    display.fullscreen = get_idata("bFullScreen", file);
    display.windowed = get_idata("bWindowed", file);
    display.vsync = get_idata("bVsync", file);
    display.frames = get_idata("iFrames", file);
    display.fov = get_idata("iFOV", file);
    check_display(&display);
    return display;
}

static audio_t get_audio(const char **file)
{
    audio_t audio = {0};

    audio.master = get_fdata("fMaster", file);
    audio.vfx = get_fdata("fVfx", file);
    audio.music = get_fdata("fMusic", file);
    check_audio(&audio);
    return audio;
}

static gameplay_t get_gameplay(const char **file)
{
    gameplay_t gameplay = {0};

    gameplay.mini_map_size = get_idata("iMiniMapSize", file);
    gameplay.sensitivity = get_fdata("fSensitivity", file);
    check_gameplay(&gameplay);
    return gameplay;
}

static keybinds_t get_keybinds(const char **file)
{
    keybinds_t keybinds = {0};

    keybinds.move_forward = get_sdata("sMove_Forward", file);
    keybinds.move_backward = get_sdata("sMove_Backward", file);
    keybinds.move_left = get_sdata("sMove_Left", file);
    keybinds.move_right = get_sdata("sMove_Right", file);
    keybinds.look_left = get_sdata("sLook_Left", file);
    keybinds.look_right = get_sdata("sLook_Right", file);
    keybinds.hotkey_1 = get_sdata("sHotkey_1", file);
    keybinds.hotkey_2 = get_sdata("sHotkey_2", file);
    keybinds.hotkey_3 = get_sdata("sHotkey_3", file);
    keybinds.hotkey_4 = get_sdata("sHotkey_4", file);
    keybinds.hotkey_5 = get_sdata("sHotkey_5", file);
    keybinds.interact = get_sdata("sInteract", file);
    keybinds.right_hand = get_sdata("sRightHand", file);
    keybinds.left_hand = get_sdata("sLeftHand", file);
    keybinds.torch = get_sdata("sTorch", file);
    check_keybinds(&keybinds);
    return keybinds;
}

settings_t get_settings(void)
{
    settings_t settings = {0};
    char **file = file_to_array("GamePrefs.ini", "\n");

    settings.display = get_display(file);
    settings.audio = get_audio(file);
    settings.gameplay = get_gameplay(file);
    settings.keybinds = get_keybinds(file);
    free_array(file);
    return settings;
}
