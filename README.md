# thu_cpp
清华大学cpp学堂在线代码以及相关笔记

shift+command+p 搜索
变成中文操作
“Ctrl+Shift+P”组合键以显示“命令面板”，然后键入“display”以筛选并显示“Configure Display Language”命令。按“Enter”，然后会按区域设置显示安装的语言列表，并突出显示当前语言设置。

重新出现波浪线提示错误
在中文环境下 按快捷键：ctrl+shift+p ，输入"启用错误波形曲线"，并点击
启用后之后，比如当包含的头文件写错后，就会出现波浪线警告。

clang++ 进行debug修改launch.json出处：bilibili两行代码
"program": "${fileDirname}/${fileBasenameNoExtension}", 
"preLaunchTask": "C/C++: clang++ 生成活动文件"