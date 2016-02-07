Arm none eabi Wizard Plugin
----------------------------
A Code::Blocks Plugin to provide a project template wizard for new gcc-arm-none-eabi Project.

NOTE: templates.7z and jlinkdevices.csv in plugin come from emIDE Embedded Application Wizard.


Author:    YWX (wxFortranIndent@163.com)
Created:   2014-5-28
Copyright: (c) YWX <wxFortranIndent@163.com>
License:   GNU General Public License, version 3

Support available for ARM7,Cortex-M0/M0+/M1/M3/M4 and Renesas RX targets.

Send bug reports and questions to YWX <wxFortranIndent@163.com>, or see http://www.emide.org/

Please notice that often trying to correct the bug yourself is the
quickest way to fix it. Even if you fail to do it, you may
discover valuable information allowing us to fix it while doing
it. We also give much higher priority to bug reports with patches
fixing the problems so this ensures that your report will be
addressed sooner.

To get the source code, please visit https://github.com/ywx/cbArmNoneEabiWizard
Get a local copy of the Arm none eabi Wizard Plugin repository with this command:
git clone git://github.com/ywx/cbArmNoneEabiWizard.git cbArmNoneEabiWizard-ReadOnly

For information on Git，please see http://git-scm.com/ or https://github.com/git/git
For information on Git for Windows，please see https://git-for-windows.github.io

Keep source code for project only in master branch. Download prebuilt ArmNoneEabiWizard.cbplugin from https://github.com/ywx/cbArmNoneEabiWizard/releases .


Compilers and Options ( for Windows )
=====================================
1, For windows, MinGW complier is preferred, combined with Code::Blocks.
2, Please download wxWidgets source code, to produce the single dynamic link library SDK.
3, Please download Code::Blocks source code, to produce Code::Blocks SDK with wxWidgets SDK in step 2.
4, Please download Arm none eabi Wizard Plugin source code, open ArmNoneEabiWizard.cbp to build with wxWidgets and Code::Blocks SDK in step 2 and 3 under "Win32 Release" or "Win32 Debug" Build targer.

For information on MinGW, please see http://www.mingw.org
For information on MinGW TDM-GCC, please see http://tdm-gcc.tdragon.net
For information on wxWidgets, please see http://www.wxwidgets.org
For information on Code::Blocks, please see http://www.codeblocks.org
For information on Code::Blocks Plug-In development, please see http://wiki.codeblocks.org/index.php?title=Developer_documentation
For information on emIDE, please see http://www.emide.org/


Compilers and Options ( for Linux )
=====================================
1, Install wxBase, wxGTK and xterm for Code::Blocks.
2, Please download Code::Blocks for Linux, to set up develop IDE.
3, Install gcc-g++, wxGTK-devel, codeblocks-devel and codeblocks-contrib-devel to build Code::Blocks Plugin.
4, Please download Arm none eabi Wizard Plugin source code, open ArmNoneEabiWizard-unix.cbp to build in Code::Blocks under "Unix Release" or "Unix Debug" Build targer.

For information on Fedora, please see http://www.fedoraproject.org
For information on Deian, please see http://www.debian.org
For information on gcc, please see http://gcc.gnu.org
For information on wxWidgets, please see http://www.wxwidgets.org
For information on Code::Blocks, please see http://www.codeblocks.org
For information on Code::Blocks Plug-In development, please see http://wiki.codeblocks.org/index.php?title=Developer_documentation
For information on emIDE, please see http://www.emide.org/


Setup and Use
=====================================
1, Download A Extended Scripted Wizard Plugin for Code::Blocks source code, Build the scriptedwizard.cbplugin
   or Download prebuilt scriptedwizard.cbplugin from https://github.com/ywx/cbScriptedWizardPlugin/releases
2, Download Arm none eabi Wizard Plugin for Code::Blocks source code, Build the ArmNoneEabiWizard.cbplugin
   or Download prebuilt ArmNoneEabiWizard.cbplugin from https://github.com/ywx/cbArmNoneEabiWizard/releases
3, Download and Install GNU Tools for ARM Embedded Processors, Set "GNU GCC Compiler for ARM" for GNU Tools for ARM Embedded Processors in Code::Blocks Compiler settings Dialog
4, Disable the Scripted wizard in Code::Blocks Manage plugins Dialog, Uncheck "Install system-wide,for all users of this machine (requires administrative rights)" and "Ask for confirmation if conflicts arise", Install the scriptedwizard.cbplugin and ArmNoneEabiWizard.cbplugin, Close Code::Blocks
5, Extract the templates.7z in the Code::Blocks Data folder in user's dir
6, Reboot Code::Blocks, Enable the Scripted wizard in Code::Blocks Manage plugins Dialog
7, Now New Project, Arm Embedded App will appear in New from template Dialog

For information on A Extended Scripted Wizard Plugin for Code::Blocks, please see https://github.com/ywx/cbScriptedWizardPlugin
For information on ARM, please see http://www.arm.com/
For information on GNU Tools for ARM Embedded Processors, please see https://launchpad.net/gcc-arm-embedded
For information on Renesas, please see http://www.renesas.com/
For information on KPIT GNU Tools, please see http://www.kpitgnutools.com/


Last updated: February 6th 2016




Arm none eabi Wizard Plugin
----------------------------
一个提供创建 gcc-arm-none-eabi 项目模板向导的 Code::Blocks 插件。

注意：插件中的 templates.7z 和 jlinkdevices.csv 来自 emIDE Embedded Application Wizard。

作者:    YWX (wxFortranIndent@163.com)
创建于:  2014-5-28
Copyright: (c) YWX <wxFortranIndent@163.com>
License:   GNU General Public License, version 3

向导提供 ARM7，Cortex-M0/M0+/M1/M3/M4 和 Renesas RX 项目模板。

有 Bug 和使用问题，请发送邮件到 YWX <wxFortranIndent@163.com>；或访问 http://www.emide.org/

插件的源代码仓库托管在 https://github.com/ywx/cbArmNoneEabiWizard
你可以用以下命令得到代码仓库的一份只读拷贝。
git clone git://github.com/ywx/cbArmNoneEabiWizard.git cbArmNoneEabiWizard-ReadOnly

关于 Git，请访问 http://git-scm.com/ 或 https://github.com/git/git
关于 Git for Windows，请访问 https://git-for-windows.github.io

仓库 master 分支只保留用于项目构建的源代码。预编译的 ArmNoneEabiWizard.cbplugin 可从 https://github.com/ywx/cbArmNoneEabiWizard/releases 下载。


编译插件（Windows 平台）：
========================
1，Windows 最好请用 MinGW 编译器和 Code::Blocks 集成开发环境。
2，请下载 wxWidgets 源代码，编译生成单一的动态链接库 wxWidgets SDK。
3，请下载 Code::Blocks 源代码，用步骤2生成的 wxWidgets SDK编译生成 Code::Blocks SDK。
4，请从上述代码仓库上下载 Arm none eabi Wizard Plugin 源代码。用步骤2和3生成的 wxWidgets 和 Code::Blocks SDK在 Code::Blocks 使用 "Win32 Release" 或 "Win32 Debug" Build targer 编译。

关于 MinGW32，请访问 http://www.mingw.org
关于 MinGW TDM-GCC，请访问 http://tdm-gcc.tdragon.net
关于 wxWidgets，请访问 http://www.wxwidgets.org
关于 Code::Blocks，请访问 http://www.codeblocks.org
关于 Code::Blocks Plug-In 开发，请访问  http://wiki.codeblocks.org/index.php?title=Developer_documentation
关于 emIDE，请访问 http://www.emide.org/

编译插件（Linux 平台）
=====================================
1, 安装 Code::Blocks 前，先安装相应 wxBase 和 wxGTK 运行包 及 xterm 。
2, 下载相应 Code::Blocks for Linux 并安装，构建开发 IDE。
3, 安装 gcc-g++, wxGTK-devel, codeblocks-devel 和 codeblocks-contrib-devel 开发包，用于编译 Code::Blocks Plugin。
4, 请从上述代码仓库下载 Arm none eabi Wizard Plugin 源代码。用 Code::Blocks 在 "Linux Release" 或 "Linux default" Build targer 下编译。

关于 Fedora，请访问 see http://www.fedoraproject.org
关于 Deian，请访问 see http://www.debian.org
关于 gcc，请访问 http://gcc.gnu.org
关于 wxWidgets，请访问 http://www.wxwidgets.org
关于 Code::Blocks，请访问 http://www.codeblocks.org
关于 Code::Blocks Plug-In development，请访问 http://wiki.codeblocks.org/index.php?title=Developer_documentation
关于 emIDE，请访问 http://www.emide.org/


安装使用
=====================================
1, 下载 A Extended Scripted Wizard Plugin for Code::Blocks 源代码, 编译构建 scriptedwizard.cbplugin
   或 从 https://github.com/ywx/cbScriptedWizardPlugin/releases 下载预编译的 scriptedwizard.cbplugin 
2, 下载 Arm none eabi Wizard Plugin for Code::Blocks 源代码, 编译构建 ArmNoneEabiWizard.cbplugin
   或 从 https://github.com/ywx/cbArmNoneEabiWizard/releases 下载预编译的 ArmNoneEabiWizard.cbplugin 
3, 下载并安装 GNU Tools for ARM Embedded Processors, 在 Code::Blocks Compiler settings Dialog 中,为 GNU Tools for ARM Embedded Processors 配置 "GNU GCC Compiler for ARM"
4, 在 Code::Blocks Manage plugins Dialog 中 Disable Scripted wizard 插件, Uncheck "Install system-wide,for all users of this machine (requires administrative rights)" 和 "Ask for confirmation if conflicts arise", 安装构建好的 scriptedwizard.cbplugin 和 ArmNoneEabiWizard.cbplugin, 然后关闭 Code::Blocks
5, 在 Code::Blocks Data folder in user's dir 中解压 templates.7z
6, 重启 Code::Blocks, 在 Manage plugins Dialog 中 Enable the Scripted wizard 插件
7, 现在 New Project, Arm Embedded App 会出现在 New from template Dialog

关于 A Extended Scripted Wizard Plugin for Code::Blocks, 请访问 https://github.com/ywx/cbScriptedWizardPlugin
关于 ARM, 请访问 http://www.arm.com/
关于 GNU Tools for ARM Embedded Processors, 请访问 https://launchpad.net/gcc-arm-embedded
关于 Renesas, 请访问 http://www.renesas.com/
关于 KPIT GNU Tools, 请访问 http://www.kpitgnutools.com/


Arm none eabi Wizard Plugin 只是将 emIDE Embedded Application Wizard 移植到 Code::Blocks Release。


最后更新: 2016-2-6
