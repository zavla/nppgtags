/**
 *  \file
 *  \brief  GTags AutoComplete window
 *
 *  \author  Pavel Nedev <pg.nedev@gmail.com>
 *
 *  \section COPYRIGHT
 *  Copyright(C) 2014-2015 Pavel Nedev
 *
 *  \section LICENSE
 *  This program is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License version 2 as published
 *  by the Free Software Foundation.
 *
 *  This program is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 *  or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 *  for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#pragma once


#include <windows.h>
#include <tchar.h>
#include "Common.h"
#include "CmdDefines.h"


namespace GTags
{

/**
 *  \class  AutoCompleteWin
 *  \brief
 */
class AutoCompleteWin
{
public:
    static void Register();
    static void Unregister();

    static void Show(const CmdPtr_t& cmd);

private:
    static const TCHAR  cClassName[];
    static const int    cBackgroundColor;
    static const int    cWidth;

    static LRESULT APIENTRY wndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

    AutoCompleteWin(const CmdPtr_t& cmd);
    AutoCompleteWin(const AutoCompleteWin&);
    ~AutoCompleteWin();
    AutoCompleteWin& operator=(const AutoCompleteWin&) = delete;

    HWND composeWindow(const TCHAR* header);
    int filterLV(const CText& filter);
    void resizeLV();

    void onDblClick();
    bool onKeyDown(int keyCode);

    static AutoCompleteWin* ACW;

    HWND            _hWnd;
    HWND            _hLVWnd;
    HFONT           _hFont;
    const CmdId_t   _cmdId;
    const int       _cmdTagLen;
    ParserPtr_t     _completion;
};

} // namespace GTags
