# OOP-Refactor

Refactor a submission to our judge system with all the techniques you have learned, and write a report with a GitHub public repository along with its refactor history. 

github: https://github.com/b09902056/OOP-Refactor



## Problem: 249. Company

![](./graph.jpg)

## Refactor Steps

1. 把原本的 C 程式轉換成 C++ 版本，使用 cin, cout, vector, string。

2. 把程式改成 structural programming。把原本的一坨程式碼拆出許多 function。有個重複使用到的程式部份，原本是用複製貼上，現在改成 function。function 的參數，也有使用 C++ 的 reference。

    把程式改成 modular programming。把 structure `Employee` 和他相關的 function 拆出來新的檔案 `employee.h`, `employee.cc`。`main.cc` 再去 `#include "employee.h"`。

3. 把程式改成 OOP。現在有三個 class `Employee, EmployeeList, Query`。`Employee` 是單一個員工的屬性和 methods，`EmployeeList` 是全部員工的集合，儲存了所有的 `Employee`，和相關的 methods。`Query`是負責最後的查詢員工關係。OOP 的技術中，有使用 private, public、constructor。