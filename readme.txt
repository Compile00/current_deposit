①实验环境：windows10 + codeblock20.03
②有两个txt文本,分别为record和record2; 其中record存放账户信息，record2存放交易记录,他们都放在源文件相同的文件夹下，这样在编译运行代码时就能读写到这两个文本文件。
③工程文件中有7个源文件和1个头文件，其中需要若按编译顺序则先编译ListInsert.cpp, getTime.cpp, inquire.cpp, ListDelete.cpp, inquire.cpp, accout.cpp, main.cpp。
④在“活期储蓄账目管理系统\bin\Debug”文件夹中含有可执行文件和两个文本文件，文本文件分别为record和record2，和文件夹外的那两个文本文件是一样的，放在里面是为了可以单独运行exe可执行文件，如果缺少两个文本文件，可执行文件就运行不了，它运行时需要读入文件信息，但是读写文件操作中没有指定路径，所以就放在同一个文件夹下。
