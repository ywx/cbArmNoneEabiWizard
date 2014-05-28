/***************************************************************
 * Name:      ArmNoneEabiWizard
 * Purpose:   Code::Blocks Plugin to provide a wizard for new
 * gcc-arm-none-eabi Project
 * Author:    YWX (wxFortranIndent@163.com)
 * Created:   2014-05-28
 * Copyright: (c) YWX <wxFortranIndent@163.com>
 * License:   GNU General Public License, version 3
 **************************************************************/

#include <sdk.h> // Code::Blocks SDK
#include <configurationpanel.h>
#include "ArmNoneEabiWizard.h"

// Register the plugin with Code::Blocks.
// We are using an anonymous namespace so we don't litter the global one.
namespace
{
    PluginRegistrant<ArmNoneEabiWizard> reg(_T("ArmNoneEabiWizard"));
}


// events handling
BEGIN_EVENT_TABLE(ArmNoneEabiWizard, cbPlugin)
    // add any events you want to handle here
END_EVENT_TABLE()

// constructor
ArmNoneEabiWizard::ArmNoneEabiWizard()
{
    // Make sure our resources are available.
    // In the generated boilerplate code we have no resources but when
    // we add some, it will be nice that this code is in place already ;)
    if(!Manager::LoadResource(_T("ArmNoneEabiWizard.zip")))
    {
        NotifyMissingFile(_T("ArmNoneEabiWizard.zip"));
    }
}

// destructor
ArmNoneEabiWizard::~ArmNoneEabiWizard()
{
}

void ArmNoneEabiWizard::OnAttach()
{
    // do whatever initialization you need for your plugin
    // NOTE: after this function, the inherited member variable
    // m_IsAttached will be TRUE...
    // You should check for it in other functions, because if it
    // is FALSE, it means that the application did *not* "load"
    // (see: does not need) this plugin...
}

void ArmNoneEabiWizard::OnRelease(bool appShutDown)
{
    // do de-initialization for your plugin
    // if appShutDown is true, the plugin is unloaded because Code::Blocks is being shut down,
    // which means you must not use any of the SDK Managers
    // NOTE: after this function, the inherited member variable
    // m_IsAttached will be FALSE...
}

int ArmNoneEabiWizard::Configure()
{
    //create and display the configuration dialog for your plugin
    //cbConfigurationDialog dlg(Manager::Get()->GetAppWindow(), wxID_ANY, _("Your dialog title"));
    //cbConfigurationPanel* panel = GetConfigurationPanel(&dlg);
    //if (panel)
    //{
    //    dlg.AttachConfigurationPanel(panel);
    //    PlaceWindow(&dlg);
    //    return dlg.ShowModal() == wxID_OK ? 0 : -1;
    //}
    //return -1;
    return 0;
}

void ArmNoneEabiWizard::BuildMenu(wxMenuBar* menuBar)
{
    //The application is offering its menubar for your plugin,
    //to add any menu items you want...
    if( !IsAttached() )
    {
        return;
    }
    //Append any items you need in the menu...
    //NOTE: Be careful in here... The application's menubar is at your disposal.
    NotImplemented(_T("ArmNoneEabiWizard::BuildMenu()"));
}

void ArmNoneEabiWizard::BuildModuleMenu(const ModuleType type, wxMenu* menu, const FileTreeData* data)
{
    //Some library module is ready to display a pop-up menu.
    //Check the parameter \"type\" and see which module it is
    //and append any items you need in the menu...
    //TIP: for consistency, add a separator as the first item...
    if( ( ! menu ) || ( ! IsAttached() ) )
    {
        return;
    }
    NotImplemented(_T("ArmNoneEabiWizard::BuildModuleMenu()"));
}

bool ArmNoneEabiWizard::BuildToolBar(wxToolBar* toolBar)
{
    //The application is offering its toolbar for your plugin,
    //to add any toolbar items you want...
    //Append any items you need on the toolbar...
    NotImplemented(_T("ArmNoneEabiWizard::BuildToolBar()"));

    // return true if you add toolbar items
    return false;
}
