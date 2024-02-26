---
layout: page
permalink: /keyboard_shortcuts/
title: keyboard shortcuts
description: 
nav: false
---


I'm always looking to improve my setup for maximum productivity and a better keyboard-only workflow.

The shortcuts listed here are in no particular order.

I use a [Brazilian ABNT2](http://kbdlayout.info/KBDBR/) keyboard layout. 

--- 
### Windows / task management
- `ctrl+'`, `alt+'` - switch to Windows Terminal, or open a new instance if closed. Mapped with AutoHotkey.
- `ctrl+[1-9]`, `alt+[1-9]` - switch to the `i`-th program in the taskbar. If it doesn't exist and the `i`-th position is a pinned program, open a new instance of that program. Mapped with AutoHotkey.
- `altgr+tab`, `win+tab`, `alt+/` - same as alt tab, but don't close the list of programs. I can then navigate through the open programs using the arrow keys or typing the window name using Fuzzy search. Uses [Alt-Tab Terminator](https://www.ntwind.com/software/alttabter.html).
- `alt+0` - open [FluentSearch](https://www.fluentsearch.net/). This is my preferred way of browsing files in my PC using fuzzy search.
- `alt+-` - minimize current program. Mapped with AutoHotkey.
- `alt-F4` - close current program. I am looking for a good replacement for this that doesn't interfere with program-specific keybindings. Moving my hand to F4 is clunky.
- `alt+up`, `alt+down` - press `up` or `down` 4 times. Allows to move around faster when editing, and works with all programs. Mapped with AutoHotkey.
- `ctrl+up`, `ctrl+down` - press `ctrl+up` or `ctrl+down` 4 times. Allows for faster scrolling, and works with all programs. Mapped with AutoHotkey.
- `ctrl+shift+i` - insert formatted current date anywhere. Looks like this: "2024-02-25", and can be tweaked. Mapped with AutoHotkey.
- `alt+q` - close current tab. Mapped with AutoHotkey to work on pdf viewers, web browsers, and other programs that have tabs, since not all allow remapping this command.
- `alt+right`, `alt+left` - go to tab on the right/left. Same idea as `alt+q`.

---
### Coding

These are for VSCode and Visual Studio.

- `shift+delete` - delete current line without copying it
- `ctrl+w` - select word under cursor
- `ctrl+l` - extend line selection
- `ctrl+shift+2` - duplicate tab and split right
- `alt+ç`,`alt+~` - move tab to right/left editor (or split right/left)
- `ctrl+alt+right`, `ctrl+alt+left` - swap focus between right and left side editors. For VS2022 I use a hack to achieve this, as it doesn't have the correct keybindings: an AutoHotkey function that moves the mouse to the left/right, clicks, then moves it back to where it was originally.
- `alt+´` - cycle between left and right editors
- `ctrl+j`, `alt+j` - toggle in-editor terminal
- `alt+d` - toggle left panel
- `F12` - go to definition. If we are at the definition, go to implementation.
- `F11` - go back
- `ctrl+n`, `ctrl+t` - new empty tab
- `alt+s` - go to symbol in workspace/solution
- `alt+m` - go to symbol in current file
- `alt+p` - go to file
- `ctrl+g`,`alt+g` - go to line
- `ctrl+shift+p` - editor command. VSCode only.
- `alt+q` - close current tab
- `alt+w` - toggle word wrap
- `F2` - rename
- `alt+o` - swap between source/header (C/C++)
- `ctrl+[`, `alt+[`, `shift+alt+right` (experimental) - expand selection
- `ctrl+]`, `alt+]`, `shift+alt+left` (experimental) - shrink selection
- `ctrl+d` - duplicate current line
- `shift+alt+up`, `shift+alt+down` - add new cursor above/below
- `ctrl+i` - open copilot prompt
- `alt+k` - show hover tip under cursor
- `ctrl+b`, `alt+b`, `ctrl+m` (experimental) - jump to closing bracket of current scope. If at closing bracket, jump instead to the corresponding open bracket.
- `ctrl+shift+b`, `alt+shift+b`, `ctrl+shift+m` (experimental) - similar to above, but jump while selecting text
- `ctrl+l`, `alt+l` - format selected text. If nothing is selected, format current line
- `ctrl+shift+f` - find all references
- `ctrl+shift+l` - format file
- `ctrl+,` - show format actions 
- `ctrl+.`, `alt+.` - toggle fold/unfold
- `ctrl+;`, `alt+;`, `ctrl+/` - toggle line comment
- `ctrl+shift+;`, `ctrl+shift+/` - toggle block comment
- `F7` - focus on code editor (if previously focused on another panel)
- `shift+alt+e` - toggle build errors panel
- `shift+alt+o` - toggle build output panel
- `shift+alt+k` - toggle VisualAssist find reference results. VS2022 only.
- `F5` - start debugging (VS2022 only)

---
### Web browsing

- `alt+q` - close current tab
- `alt+right`, `alt+left` - go to tab on the right/left
- `ctrl+t` - open new tab
- `F6` - move to url edit
- I use Vimium for Firefox to browse the web with keyboard only. Besides the default Vimium shortcuts, I use:
  - `g` - open link in new tab, and don't switch to it
  - `ql` - close tabs to the left
  - `qr` - close tabs to the right
  - `w` - scroll up
  - `s` - scroll down
  - `d` - scroll half page down
  - `a` - scroll half page up
  - I particularly like using 'wasd' here since when I browse with the mouse, it allows to quickly move around the page with my left hand.

---
### Gaming

- *Tibia* 
  - I have a complex AutoHotkey script to allow playing Tibia keyboard-only. Doing this is somewhat controversial in the game's community. Some people consider this cheating (I don't).
- *Stardew Valley*
  - `h` - left click. To avoid right hand fatigue.
  - `g` - right click. To avoid right hand fatigue.
  - `Home` - toggle inventory.
  - `mouse side 1`, `mouse side 2` - left click + animation cancelling
  - `mouse middle` - spam right click 8 times
- Any grand-strategy game (e.g. *EU4, CK3*): 
  - `n` - left click. To avoid right hand fatigue.
  - `m` - right click. To avoid right hand fatigue.
- Any first-person game (e.g. *Skyrim, Minecraft*)
  - `c`, `mouse side 1`, `mouse side 2` - hold left click until I press `c` again
  - `alt+w` - hold `w` until I press `w` again
  - remap `shift` for running and `ctrl` for crouching/stalking

---
### Unused 

Unused hotkeys that I'd like to use in the future.

- `ctrl+Enter` when editing
- `shift+Enter` when editing
- `ctrl+q`
- `alt+e`
- `alt+r` - currently set to "rename", but I use F2 much more.
- `ctrl+u`, `alt+u`
- `ctrl+o`
- `ctrl+p`?
- `alt+f`
- `alt+n`
- `alt+=`
- better use of F keys
- `altgr` is underused. Unfortunately most programs won't let you remap it, so this has to be done using AutoHotkey.

---
### TODO

- Improve file exploration setup. I'm bad at this.
- A way to move programs around in the taskbar using the keyboard.
- Alternatives to `ctrl+right` and `ctrl+left` for moving around a line more efficiently, akin to `w`, `e` and `b` in vim.
- Code bookmarks?
- Use less LCtrl. I have short hands and get fatigue from using this key repeatedly.
- Hotkey to jump to next open/closing brace/square bracket/parenthesis.
- Hotkey to jump to next/previous code block.
- Find a way to allow VSCode to duplicate current tab inside the same tab group.

---