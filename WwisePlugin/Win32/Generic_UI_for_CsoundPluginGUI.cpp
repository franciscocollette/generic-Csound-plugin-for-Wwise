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

#include "../stdafx.h"  
#include "Generic_UI_for_CsoundPluginGUI.h"

#include "../resource.h"


AK_WWISE_PLUGIN_GUI_WINDOWS_BEGIN_POPULATE_TABLE(MyPluginProp)
AK_WWISE_PLUGIN_GUI_WINDOWS_POP_ITEM(IDC_CHECK1, "CheckBox1")
AK_WWISE_PLUGIN_GUI_WINDOWS_POP_ITEM(IDC_CHECK2, "CheckBox2")
AK_WWISE_PLUGIN_GUI_WINDOWS_POP_ITEM(IDC_CHECK3, "CheckBox3")
AK_WWISE_PLUGIN_GUI_WINDOWS_POP_ITEM(IDC_CHECK4, "CheckBox4")
AK_WWISE_PLUGIN_GUI_WINDOWS_POP_ITEM(IDC_CHECK5, "CheckBox5")
AK_WWISE_PLUGIN_GUI_WINDOWS_POP_ITEM(IDC_CHECK6, "CheckBox6")
AK_WWISE_PLUGIN_GUI_WINDOWS_POP_ITEM(IDC_CHECK7, "CheckBox7")
AK_WWISE_PLUGIN_GUI_WINDOWS_POP_ITEM(IDC_CHECK8, "CheckBox8")
AK_WWISE_PLUGIN_GUI_WINDOWS_END_POPULATE_TABLE()

bool Generic_UI_for_CsoundPluginGUI::GetDialog(AK::Wwise::Plugin::eDialog in_eDialog, UINT& out_uiDialogID, AK::Wwise::Plugin::PopulateTableItem*& out_pTable) const
{
	switch (in_eDialog)
	{
	case AK::Wwise::Plugin::SettingsDialog:
		out_uiDialogID = IDD_PROPPAGE_LARGE;   // this can be found in the resource.h
		out_pTable = MyPluginProp;
		return true;

	case AK::Wwise::Plugin::ContentsEditorDialog:
//		out_uiDialogID = IDD_SINEPLUGIN_SMALL;
		out_pTable = NULL;
		return false;     // I think it returns a generic one like this
	}

	return false;
}

bool Generic_UI_for_CsoundPluginGUI::WindowProc(AK::Wwise::Plugin::eDialog in_eDialog, HWND in_hWnd, UINT in_message, WPARAM in_wParam, LPARAM in_lParam, LRESULT& out_lResult)
{
	out_lResult = 0;
	return false;
}

bool Generic_UI_for_CsoundPluginGUI::Help(HWND in_hWnd, AK::Wwise::Plugin::eDialog in_eDialog, const char* in_szLanguageCode) const
{
	/* AFX_MANAGE_STATE(::AfxGetStaticModuleState());
	DWORD dwTopic = ONLINEHELP::Sine_Properties;
	if (in_eDialog == AK::Wwise::Plugin::ContentsEditorDialog)
		dwTopic = ONLINEHELP::Sound_Object_Sine;
	::SendMessage(in_hWnd, WM_AK_PRIVATE_SHOW_HELP_TOPIC, dwTopic, 0);
	return true;*/
	return false;    /// I have to do this because it is a pure virtual function in the base class and needed to be overriden and then implemented...
}
/*   
BOOL Generic_UI_for_CsoundPluginGUI::OnInitDialog(HWND in_hWnd)
{
	// Initialize the edit control
	m_editControl.SubclassDlgItem(IDC_EDIT1, m_hwndPropView);  //
	// Optionally set initial text
	m_editControl.SetWindowText(_T("Initial Text"));
	return TRUE;  // return TRUE unless you set the focus to a control
}*/



AK_ADD_PLUGIN_CLASS_TO_CONTAINER(Generic_UI_for_Csound, Generic_UI_for_CsoundPluginGUI, Generic_UI_for_CsoundSource);

