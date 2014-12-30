lkm-rootkit
===========

an lkm rootkit support x86/64,arm,mips

支持 kernel version 2.6 及 3.x ,

支持 x86, x86_64, arm, mips 平台，

支持进程隐藏、进程免杀（root 无法 kill）

支持文件隐藏、文件免杀（root 无法修改、删除）

支持tcpv4/v6端口隐藏、udpv4/v6端口隐藏

支持模块本身隐藏

支持提权

支持应用层接口下发执行功能的命令

源码主体源于国外一位大牛写的 suterusu 项目。
本人在此基础上添加了mips架构的支持，以及进程免杀、文件免杀等功能。
