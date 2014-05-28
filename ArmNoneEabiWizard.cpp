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
#include <globals.h>
#include <cbexception.h>
#include <manager.h>
#include <scriptingmanager.h>
#include <scripting/bindings/sc_base_types.h>
#include <configmanager.h>

//#include <configurationpanel.h>
#include "ArmNoneEabiWizard.h"

#include <wx/arrimpl.cpp>
WX_DEFINE_OBJARRAY(JLinkDevices);

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
    RegisterWizard();
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



//"Manufacturer,";"Device,";"Core,";"{Flash";"areas},";"{RAM";"areas}";;;;
//"Actel,";"A2F200M3F,";"Cortex-M3,";"{0x00000000,";"0x00000000},";"{0x00000000,";"0x00000000}";;;;
static wxRegEx regDevice1ROM1RAM(_T("\\\"([A-Za-z0-9 ]+)\\\", \\\"([-A-Za-z0-9 ]+)\\\", \\\"([-A-Za-z0-9 ]+)\\\", {([0-9A-Fa-fx]+), ([0-9A-Fa-fx]+)}, {([0-9A-Fa-fx]+), ([0-9A-Fa-fx]+)}"));
//
// 1: Manufacturer
// 2: Device Name
// 3: Core
// 4: ROM Start
// 5: ROM Size
// 6: RAM Start
// 7: RAM Size
//

// "Analog", "ADuCM330", "Cortex-M3", { {0x00000000, 0x00018000}, {0x00040000, 0x00001000} }, {0x20000000, 0x00001800}
static wxRegEx regDevice2ROM1RAM(_T("\\\"([A-Za-z0-9 ]+)\\\", \\\"([-A-Za-z0-9 ]+)\\\", \\\"([-A-Za-z0-9 ]+)\\\", { {([0-9A-Fa-fx]+), ([0-9A-Fa-fx]+)}, {([0-9A-Fa-fx]+), ([0-9A-Fa-fx]+)} }, {([0-9A-Fa-fx]+), ([0-9A-Fa-fx]+)}"));
//
// 1: Manufacturer
// 2: Device Name
// 3: Core
// 4: ROM0 Start
// 5: ROM0 Size
// 6: ROM1 Start
// 7: ROM1 Size
// 8: RAM Start
// 9: RAM Size
//

// "TI", "TMS470R1A288", "ARM7TDMI", { {0x00000000, 0x00001FE0}, {0x00002000, 0x00006000}, {0x00040000, 0x00040000} }, {0x00400000, 0x00004000}
static wxRegEx regDevice3ROM1RAM(_T("\\\"([A-Za-z0-9 ]+)\\\", \\\"([-A-Za-z0-9 ]+)\\\", \\\"([-A-Za-z0-9 ]+)\\\", { {([0-9A-Fa-fx]+), ([0-9A-Fa-fx]+)}, {([0-9A-Fa-fx]+), ([0-9A-Fa-fx]+)}, {([0-9A-Fa-fx]+), ([0-9A-Fa-fx]+)} }, {([0-9A-Fa-fx]+), ([0-9A-Fa-fx]+)}"));
//
// 1: Manufacturer
// 2: Device Name
// 3: Core
// 4: ROM0 Start
// 5: ROM0 Size
// 6: ROM1 Start
// 7: ROM1 Size
// 8: ROM2 Start
// 9: ROM2 Size
//10: RAM Start
//11: RAM Size
//

void ArmNoneEabiWizard::GetJLinkDevices(void)
{
    wxString        PathDeviceCSV;
    wxFile          FileDeviceCSV;
    wxString        ContentDeviceCSV;
    wxArrayString   LinesDeviceCSV;
    JLinkDeviceInfo device;

    unsigned int    CurLine;

    //
    // Find CSV file
    //
    PathDeviceCSV = ConfigManager::GetExecutableFolder() + wxFILE_SEP_PATH + _T("share") + wxFILE_SEP_PATH + _T("CodeBlocks") + wxFILE_SEP_PATH + _T("JLinkDevices.csv");
    //
    // Read csv file
    //
    if(!FileDeviceCSV.Open(PathDeviceCSV))
    {
        return;
    }
    ContentDeviceCSV = cbReadFileContents(FileDeviceCSV);
    LinesDeviceCSV = GetArrayFromString(ContentDeviceCSV, _T("\r\n"), 0);
    //
    // Parse CSV file line by line and add device to array
    //
    for (CurLine = 1; CurLine < LinesDeviceCSV.GetCount(); CurLine++)
    {
        if (regDevice1ROM1RAM.Matches(LinesDeviceCSV.Item(CurLine)))
        {
            device.Manufacturer = regDevice1ROM1RAM.GetMatch(LinesDeviceCSV.Item(CurLine), 1);
            device.DeviceName   = regDevice1ROM1RAM.GetMatch(LinesDeviceCSV.Item(CurLine), 2);
            device.Core         = regDevice1ROM1RAM.GetMatch(LinesDeviceCSV.Item(CurLine), 3);
            //
            // Do not continue if core is not ARM
            //
            if (device.Core.IsSameAs(_T("Coldfire")))
            {
                continue;
            }
            //
            // For some cores we do not have generic startups yet. Continue
            //
            if (device.Core.IsSameAs(_T("Unspecified")) ||
                    device.Core.IsSameAs(_T("ARM9")) ||
                    device.Core.IsSameAs(_T("ARM926EJ-S")) ||
                    device.Core.IsSameAs(_T("ARM966E-S")) ||
                    device.Core.IsSameAs(_T("ARM968E-S")) ||
                    device.Core.IsSameAs(_T("ARM11")) ||
                    device.Core.IsSameAs(_T("Cortex-A5")) ||
                    device.Core.IsSameAs(_T("Cortex-A8")) ||
                    device.Core.IsSameAs(_T("Cortex-A9")) ||
                    device.Core.IsSameAs(_T("Cortex-R4"))
               )
            {
                continue;
            }

            device.ROMAreas.Clear();
            device.ROMSizes.Clear();
            device.RAMAreas.Clear();
            device.RAMSizes.Clear();

            device.ROMAreas.Add(regDevice1ROM1RAM.GetMatch(LinesDeviceCSV.Item(CurLine), 4));
            device.ROMSizes.Add(regDevice1ROM1RAM.GetMatch(LinesDeviceCSV.Item(CurLine), 5));
            device.RAMAreas.Add(regDevice1ROM1RAM.GetMatch(LinesDeviceCSV.Item(CurLine), 6));
            device.RAMSizes.Add(regDevice1ROM1RAM.GetMatch(LinesDeviceCSV.Item(CurLine), 7));
            m_JLinkDevices.Add(device);
        }
        else if (regDevice2ROM1RAM.Matches(LinesDeviceCSV.Item(CurLine)))
        {
            device.Manufacturer = regDevice2ROM1RAM.GetMatch(LinesDeviceCSV.Item(CurLine), 1);
            device.DeviceName   = regDevice2ROM1RAM.GetMatch(LinesDeviceCSV.Item(CurLine), 2);
            device.Core         = regDevice2ROM1RAM.GetMatch(LinesDeviceCSV.Item(CurLine), 3);
            //
            // Do not continue if core is not ARM
            //
            if (device.Core.IsSameAs(_T("Coldfire")))
            {
                continue;
            }
            //
            // For some cores we do not have generic startups yet. Continue
            //
            if (device.Core.IsSameAs(_T("Unspecified")) ||
                    device.Core.IsSameAs(_T("ARM9")) ||
                    device.Core.IsSameAs(_T("ARM926EJ-S")) ||
                    device.Core.IsSameAs(_T("ARM966E-S")) ||
                    device.Core.IsSameAs(_T("ARM968E-S")) ||
                    device.Core.IsSameAs(_T("ARM11")) ||
                    device.Core.IsSameAs(_T("Cortex-A5")) ||
                    device.Core.IsSameAs(_T("Cortex-A8")) ||
                    device.Core.IsSameAs(_T("Cortex-A9")) ||
                    device.Core.IsSameAs(_T("Cortex-R4"))
               )
            {
                continue;
            }

            device.ROMAreas.Clear();
            device.ROMSizes.Clear();
            device.RAMAreas.Clear();
            device.RAMSizes.Clear();

            device.ROMAreas.Add(regDevice2ROM1RAM.GetMatch(LinesDeviceCSV.Item(CurLine), 4));
            device.ROMSizes.Add(regDevice2ROM1RAM.GetMatch(LinesDeviceCSV.Item(CurLine), 5));
            device.ROMAreas.Add(regDevice2ROM1RAM.GetMatch(LinesDeviceCSV.Item(CurLine), 6));
            device.ROMSizes.Add(regDevice2ROM1RAM.GetMatch(LinesDeviceCSV.Item(CurLine), 7));
            device.RAMAreas.Add(regDevice2ROM1RAM.GetMatch(LinesDeviceCSV.Item(CurLine), 8));
            device.RAMSizes.Add(regDevice2ROM1RAM.GetMatch(LinesDeviceCSV.Item(CurLine), 9));
            m_JLinkDevices.Add(device);
        }
        else if (regDevice3ROM1RAM.Matches(LinesDeviceCSV.Item(CurLine)))
        {
            device.Manufacturer = regDevice3ROM1RAM.GetMatch(LinesDeviceCSV.Item(CurLine), 1);
            device.DeviceName   = regDevice3ROM1RAM.GetMatch(LinesDeviceCSV.Item(CurLine), 2);
            device.Core         = regDevice3ROM1RAM.GetMatch(LinesDeviceCSV.Item(CurLine), 3);
            //
            // Do not continue if core is not ARM
            //
            if (device.Core.IsSameAs(_T("Coldfire")))
            {
                continue;
            }
            //
            // For some cores we do not have generic startups yet. Continue
            //
            if (device.Core.IsSameAs(_T("Unspecified")) ||
                    device.Core.IsSameAs(_T("ARM9")) ||
                    device.Core.IsSameAs(_T("ARM926EJ-S")) ||
                    device.Core.IsSameAs(_T("ARM966E-S")) ||
                    device.Core.IsSameAs(_T("ARM968E-S")) ||
                    device.Core.IsSameAs(_T("ARM11")) ||
                    device.Core.IsSameAs(_T("Cortex-A5")) ||
                    device.Core.IsSameAs(_T("Cortex-A8")) ||
                    device.Core.IsSameAs(_T("Cortex-A9")) ||
                    device.Core.IsSameAs(_T("Cortex-R4"))

               )
            {
                continue;
            }

            device.ROMAreas.Clear();
            device.ROMSizes.Clear();
            device.RAMAreas.Clear();
            device.RAMSizes.Clear();

            device.ROMAreas.Add(regDevice3ROM1RAM.GetMatch(LinesDeviceCSV.Item(CurLine), 4));
            device.ROMSizes.Add(regDevice3ROM1RAM.GetMatch(LinesDeviceCSV.Item(CurLine), 5));
            device.ROMAreas.Add(regDevice3ROM1RAM.GetMatch(LinesDeviceCSV.Item(CurLine), 6));
            device.ROMSizes.Add(regDevice3ROM1RAM.GetMatch(LinesDeviceCSV.Item(CurLine), 7));
            device.ROMAreas.Add(regDevice3ROM1RAM.GetMatch(LinesDeviceCSV.Item(CurLine), 8));
            device.ROMSizes.Add(regDevice3ROM1RAM.GetMatch(LinesDeviceCSV.Item(CurLine), 9));
            device.RAMAreas.Add(regDevice3ROM1RAM.GetMatch(LinesDeviceCSV.Item(CurLine), 10));
            device.RAMSizes.Add(regDevice3ROM1RAM.GetMatch(LinesDeviceCSV.Item(CurLine), 11));
            m_JLinkDevices.Add(device);
        }
    }
}

wxString ArmNoneEabiWizard::GetManufacturerDevices(const wxString& Manufacturer)
{
    unsigned int deviceId;
    wxString sReturn;

    sReturn = wxEmptyString;

    if (m_JLinkDevices.GetCount() == 0)
    {
        GetJLinkDevices();
    }

    for (deviceId = 0; deviceId < m_JLinkDevices.GetCount(); deviceId++)
    {
        if (m_JLinkDevices[deviceId].Manufacturer.IsSameAs(Manufacturer))
        {
            sReturn << m_JLinkDevices[deviceId].DeviceName;
            sReturn << _T(";");
        }
    }

    return sReturn;
}

wxString ArmNoneEabiWizard::GetDeviceCore(const wxString& DeviceName)
{
    unsigned int deviceId;

    if (m_JLinkDevices.GetCount() == 0)
    {
        GetJLinkDevices();
    }

    for (deviceId = 0; deviceId < m_JLinkDevices.GetCount(); deviceId++)
    {
        if (m_JLinkDevices[deviceId].DeviceName.IsSameAs(DeviceName))
        {
            return m_JLinkDevices[deviceId].Core;
        }
    }

    return wxEmptyString;
}

wxString ArmNoneEabiWizard::GetDeviceROMStart(const wxString& DeviceName)
{
    unsigned int deviceId;
    unsigned int item;
    wxString     ret;

    ret = wxEmptyString;

    if (m_JLinkDevices.GetCount() == 0)
    {
        GetJLinkDevices();
    }

    for (deviceId = 0; deviceId < m_JLinkDevices.GetCount(); deviceId++)
    {
        if (m_JLinkDevices[deviceId].DeviceName.IsSameAs(DeviceName))
        {
            for (item = 0; item < m_JLinkDevices[deviceId].ROMAreas.GetCount(); item++)
            {
                ret.Append(m_JLinkDevices[deviceId].ROMAreas.Item(item) + _(";"));
            }
            break;
        }
    }
    return ret;
}

wxString ArmNoneEabiWizard::GetDeviceROMSize(const wxString& DeviceName)
{
    unsigned int deviceId;
    unsigned int item;
    wxString     ret;

    ret = wxEmptyString;

    if (m_JLinkDevices.GetCount() == 0)
    {
        GetJLinkDevices();
    }

    for (deviceId = 0; deviceId < m_JLinkDevices.GetCount(); deviceId++)
    {
        if (m_JLinkDevices[deviceId].DeviceName.IsSameAs(DeviceName))
        {
            for (item = 0; item < m_JLinkDevices[deviceId].ROMSizes.GetCount(); item++)
            {
                ret.Append(m_JLinkDevices[deviceId].ROMSizes.Item(item) + _(";"));
            }
            break;
        }
    }
    return ret;
}

wxString ArmNoneEabiWizard::GetDeviceRAMStart(const wxString& DeviceName)
{
    unsigned int deviceId;
    unsigned int item;
    wxString     ret;

    ret = wxEmptyString;

    if (m_JLinkDevices.GetCount() == 0)
    {
        GetJLinkDevices();
    }

    for (deviceId = 0; deviceId < m_JLinkDevices.GetCount(); deviceId++)
    {
        if (m_JLinkDevices[deviceId].DeviceName.IsSameAs(DeviceName))
        {
            for (item = 0; item < m_JLinkDevices[deviceId].RAMAreas.GetCount(); item++)
            {
                ret.Append(m_JLinkDevices[deviceId].RAMAreas.Item(item) + _(";"));
            }
            break;
        }
    }
    return ret;
}

wxString ArmNoneEabiWizard::GetDeviceRAMSize(const wxString& DeviceName)
{
    unsigned int deviceId;
    unsigned int item;
    wxString     ret;

    ret = wxEmptyString;

    if (m_JLinkDevices.GetCount() == 0)
    {
        GetJLinkDevices();
    }

    for (deviceId = 0; deviceId < m_JLinkDevices.GetCount(); deviceId++)
    {
        if (m_JLinkDevices[deviceId].DeviceName.IsSameAs(DeviceName))
        {
            for (item = 0; item < m_JLinkDevices[deviceId].RAMSizes.GetCount(); item++)
            {
                ret.Append(m_JLinkDevices[deviceId].RAMSizes.Item(item) + _(";"));
            }
            break;
        }
    }
    return ret;
}


// scripting support
DECLARE_INSTANCE_TYPE(ArmNoneEabiWizard);

void ArmNoneEabiWizard::RegisterWizard()
{
    SqPlus::SQClassDef<ArmNoneEabiWizard>("ArmNoneEabiWizard").
            func(&ArmNoneEabiWizard::GetManufacturerDevices, "GetManufacturerDevices").
            func(&ArmNoneEabiWizard::GetDeviceCore, "GetDeviceCore").
            func(&ArmNoneEabiWizard::GetDeviceROMStart, "GetDeviceROMStart").
            func(&ArmNoneEabiWizard::GetDeviceROMSize, "GetDeviceROMSize").
            func(&ArmNoneEabiWizard::GetDeviceRAMStart, "GetDeviceRAMStart").
            func(&ArmNoneEabiWizard::GetDeviceRAMSize, "GetDeviceRAMSize");

    SqPlus::BindVariable( this, "ArmWizard", SqPlus::VAR_ACCESS_READ_ONLY );
}
