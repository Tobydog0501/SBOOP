# To-do List Readme

# File Structor

```shellscript
todolist/
├── Makefile
├── README.md
├── headers
│   ├── all.h
│   ├── command.h
│   ├── common.h
│   ├── debug.h
│   ├── mode.h
│   ├── task.h
│   ├── todolist.h
│   └── utils.h
├── list.txt
├── main.cpp
├── src
│   ├── command.cpp
│   ├── mode.cpp
│   ├── task.cpp
│   ├── todolist.cpp
│   └── utils.cpp
└── test.cpp
```



***

# Building up the project



## System requirements:

This project was built on WSL2 Ubuntu 22.04 but windows should be fine if the environment is well-configured.

```shellscript
sudo apt-get update
sudo apt-get install build-essential gdb
```

## Compile the code:

cd into the directory where the main.cpp lies, enter one of the below:

```shellscript
make all # if you want to run it in interative mode.
make test # if you want to run it in test mode, which just show all function it has.
```

## Execute the program:

This will create several .o files and a main file. Run

```shellscript
./main
```

After this, you will see:

```shellscript
tobydog@Ubuntu:~/cpp project/todolist$ ./main
Enter command:

```

***

# Executing all commands:



## Help command:

simply type in 'help', 'h', or '?'.

```shellscript
tobydog@Ubuntu:~/cpp project/todolist$ ./main
Enter command:
?
Help Mesage:
Commands: view, add, edit, delete, save, help, exit
Modes: all, completed, importance, date, category, name, tag
```



## Adding a new task to the list:

Type in 'add', and follow the guild.

```shellscript
Enter command:
add
Enter name:
test
Enter category:
test_cat
Enter importance:
10
Enter date(Format YYYY/MM/DD, or NONE):
2025/03/27
Enter time(Format HH:MM, or NONE):
00:00
Enter description:
this is a test task
Enter tags(stop to stop):
stop
Task added successfully
```



***

## Viewing tasks:

Type in 'view', then follow the guide.



### Viewing single task:

in the mode, type in "name", and then type in the task name you want to view.

```shellscript
Enter command:
view
Enter mode(stop to stop):
name
Enter identifier:
test
================================== Tasks ==================================
Name:test
Category:test_cat
Completed:1
Importance:10
Date:2025/03/27
Time:00:00
Description:this is a test task stop
Tag:
=========================================================================
```



### Viewing multiple tasks:

Here you can choose the following as filter:

* category
  * shows the tasks with the specfic category.
* completed
  * shows the tasks that are completed(1) or incompleted(0).
* date
  * shows the tasks that are passed(1) or not yet passed(0) based on the time you execute the command.
* tag
  * shows the tasks that have the tag.
* all
  * shows all tasks.

If you added "importance", it will print out the tasks ordered by the importance.

There can be multiple filters.

```shellscript
Enter command:
view category test_cat
Enter mode(stop to stop):
Enter identifier:
Enter mode(stop to stop):
stop
================================== Tasks ==================================
Name:test2
Category:test_cat
Completed:1
Importance:15
Date:2025/09/02
Time:00:00
Description:A very far away task
Tag:
=========================================================================
Name:test
Category:test_cat
Completed:1
Importance:10
Date:2025/03/27
Time:00:00
Description:this is a test task stop
Tag:
=========================================================================
```





***

## Deleting tasks:



### Deleting single task:

This is exactally the same as the 'view' section



### Deleting multiple tasks:

This is exactally the same as the 'view' section



***

## Editing task:



```shellscript
Enter command:
edit
Enter task name:
test
Enter type:
category
Enter new category:
not_test
Task edited!
```





***

## Saving the data



Type in "save" or "exit", then it will save the data to "list.txt" and is automatically read when the program starts.

