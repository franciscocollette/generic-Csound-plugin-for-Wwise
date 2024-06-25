/*******************************************************************************
The content of this file includes portions of the AUDIOKINETIC Wwise Technology
released in source code form as part of the SDK installer package.

Commercial License Usage

Licensees holding valid commercial licenses to the AUDIOKINETIC Wwise Technology
may use this file in accordance with the end user license agreement provided 
with the software or, alternatively, in accordance with the terms contained in a
written agreement between you and Audiokinetic Inc.

Apache License Usage

Alternatively, this file may be used under the Apache License, Version 2.0 (the 
"Apache License"); you may not use this file except in compliance with the 
Apache License. You may obtain a copy of the Apache License at 
http://www.apache.org/licenses/LICENSE-2.0.

Unless required by applicable law or agreed to in writing, software distributed
under the Apache License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES
OR CONDITIONS OF ANY KIND, either express or implied. See the Apache License for
the specific language governing permissions and limitations under the License.

  Copyright (c) 2024 Audiokinetic Inc.
*******************************************************************************/
#pragma once

#include "../Generic_UI_for_CsoundPlugin.h"
#include "../stdafx.h"  // Include necessary for CEdit  // this for the edit boxes
#include "../resource.h" 

class Generic_UI_for_CsoundPluginGUI 
	: public AK::Wwise::Plugin::RequestHost    // this i dont know but i keep adding it
	, public AK::Wwise::Plugin::PluginMFCWindows<>
	, public AK::Wwise::Plugin::GUIWindows
{
public:
	Generic_UI_for_CsoundPluginGUI() {};
	//i copied this from the sine example, idk
	virtual bool GetDialog(AK::Wwise::Plugin::eDialog in_eDialog, UINT& out_uiDialogID, AK::Wwise::Plugin::PopulateTableItem*& out_pTable) const override;
	virtual bool WindowProc(AK::Wwise::Plugin::eDialog in_eDialog, HWND in_hWnd, UINT in_message, WPARAM in_wParam, LPARAM in_lParam, LRESULT& out_lResult) override;
	virtual bool Help(HWND in_hWnd, AK::Wwise::Plugin::eDialog in_eDialog, const char* in_szLanguageCode) const override; // I have to do do this because is a pure virtual function in the base class
	
protected:
//	virtual BOOL OnInitDialog(HWND in_hWnd);  // this for the edit boxes

private:
	//HWND m_hwndPropView = nullptr;  // this is the dialog object?
	//CEdit m_editControl;  // Add member for edit control // this for the edit boxes
};
