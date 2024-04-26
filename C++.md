* C++中的命名空间（Namespace）是一种特性，用于封装一组相关的类或函数，以便在大型项目中更好地组织和管理代码。

  ```c++
  namespace MyNamespace {  
      int myVariable = 42;  
      void myFunction() {  
          // ...  
      }  
  }
  // 使用：
  int main() {  
      MyNamespace::myFunction();  // 使用命名空间前缀调用函数  
      int x = MyNamespace::myVariable;  // 使用命名空间前缀访问变量  
      return 0;  
  }
  // 或在声明，便可直接使用
  using MyNamespace::myFunction; 
  或者
  using namespace MyNamespace;
  ```

  命名空间的嵌套：

  ```c++
  namespace Outer {  
      namespace Inner {  
          int value = 10;  
      }  
  }  
    
  int main() {  
      int x = Outer::Inner::value;  // 访问嵌套命名空间中的成员  
      return 0;  
  }
  ```

  类内部的 using 声明：在类定义中，using 声明通常用于引入基类的成员，以便在派生类中可以直接使用它们，而无需通过基类名称进行限定。

  ```c++
  class Base {  
  public:  
      void foo() {}  
  };  
    
  class Derived : public Base {  
  public:  
      using Base::foo; // 引入基类的 foo 成员函数  
  };
  ```

  命名空间别名：除了引入成员，using 关键字还可以用于为命名空间创建别名，这在处理长命名空间名称或避免命名冲突时非常有用。

  ```c++
  namespace VeryLongNamespaceName {  
      // ...  
  }  
    
  using VLNN = VeryLongNamespaceName; // 创建命名空间别名
  ```

  using的使用方法

  ```c++
  基本类型别名
  using Int = int;
  using String = std::string;
  
  Int a = 42;
  String s = "Hello, World!";
  
  指针和引用类型别名
  using IntPtr = int*;
  using StringRef = std::string&;
  
  IntPtr ptr = &a;
  StringRef ref = s;
  
  函数指针类型别名
  using FuncPtr = void (*)(int, double);
  
  FuncPtr func = someFunction;
  
  模板类型别名
  template<typename T>
  using Vector = std::vector<T>;
  
  Vector<int> intVector;
  Vector<double> doubleVector;
  
  嵌套类型别名
  struct MyStruct {
      using NestedType = int;
      NestedType value;
  };
  
  MyStruct ms;
  ms.value = 42;
  ```

* 使用#define定义宏，使用#undef取消宏定义

* deque是一个双端队列（double-ended queue）容器，它允许我们在其前端和后端快速插入和删除元素。deque是C++标准模板库（STL）中的一个组件，提供了动态数组的功能，并且优化了从两端进行插入和删除的操作。与vector（动态数组）不同，deque不需要在插入或删除元素时重新分配整个内存块。因此，对于在序列两端频繁进行插入和删除操作的情况，deque通常比vector更高效。

  ```c++
  #include <deque>
  std::deque<int> emptyDeque; // 空的deque  
  std::deque<int> intDeque = {1, 2, 3, 4, 5}; // 包含初始元素的deque
  intDeque.push_front(0); // 在前端插入元素0  
  intDeque.push_back(6);  // 在后端插入元素6
  if (!intDeque.empty()) { // 检查deque是否为空  
      intDeque.pop_front(); // 删除前端元素  
      intDeque.pop_back();  // 删除后端元素  
  }
  if (!intDeque.empty()) {  
      int frontElement = intDeque.front();  // 访问前端元素  
      int backElement = intDeque.back();   // 访问后端元素  
      int middleElement = intDeque[2];      // 访问索引为2的元素（注意：索引从0开始）  
  }
  // 使用迭代器遍历  
  for (std::deque<int>::iterator it = intDeque.begin(); it != intDeque.end(); ++it) {  
      std::cout << *it << ' ';  
  }  
    
  // 使用范围基于的for循环遍历  
  for (const auto& element : intDeque) {  
      std::cout << element << ' ';  
  }
  std::size_t dequeSize = intDeque.size();  // 获取deque的大小  
  bool isDequeEmpty = intDeque.empty();       // 检查deque是否为空
  ```

  

* 在C++中，typename关键字主要用于两种场合：

  1. 在模板编程中声明类型参数：当你在模板类或模板函数中声明一个依赖的类型时，需要使用typename来告诉编译器你正在声明一个类型而不是一个静态成员。

     ```c++
     template<typename T>
     class MyClass {
         T myMember;
         // ...
     };
     
     template<typename T>
     void myFunction(T param) {
         // ...
     }
     ```

  2. 在模板类或函数内部使用嵌套依赖类型：当你在模板类或模板函数内部使用嵌套类型时，也需要使用typename。这是因为编译器在解析模板时可能无法立即知道嵌套名称是指向类型的。

     ```c++
     template<typename T>
     class Outer {
         class Inner {
             // ...
         };
         
         void func() {
             typename Outer<T>::Inner obj; // 需要使用 typename,typename Outer<T>::Inner告诉编译器Outer<T>::Inner是一个类型。
         }
     };
     ```

     

* 在C++中，将const关键字添加到函数声明的末尾表示该函数不会修改它所操作的对象的状态（即，它不会修改调用它的对象的任何成员变量）。这提供了一种方式来告诉其他程序员该函数是一个“只读”函数，它不会以任何方式更改其操作的对象。

  当你在一个成员函数后面加上const时，你实际上是在向编译器和阅读代码的其他程序员保证这个函数不会修改对象的任何成员变量（除非它们被声明为mutable）。如果你尝试在这样的函数中修改成员变量，编译器将会报错。

  ```c++
  class MyClass {
  private:
      int value;
  
  public:
      MyClass(int v) : value(v) {}
  
      int getValue() const {
          return value; // 可以读取value，但不能修改它
      }
  
      void setValue(int v) {
          value = v; // 可以修改value
      }
  
      void printValue() const {
          std::cout << value << std::endl; // 可以调用其他const成员函数
          // value = 42; // 这行代码会导致编译错误，因为我们不能修改成员变量
      }
  };
  
  int main() {
      MyClass obj(10);
      const MyClass constObj(20);
  
      obj.printValue(); // 调用非const对象上的const成员函数
  ```

  

* 在C++中，explicit是一个类型修饰符，用于防止类的构造函数进行不期望的隐式类型转换。当你将一个类的构造函数标记为explicit时，你告诉编译器这个构造函数只能用于显式转换，而不能用于隐式转换。

  隐式转换有时可能导致代码中的错误或难以发现的bug，尤其是在处理复杂的数据类型时。explicit关键字帮助开发者避免这种情况，强制要求他们显式地声明类型转换。

  ```c++
  class MyClass {
  public:
      MyClass(int value) {
          // ... 构造函数实现 ...
      }
  
      // 其他成员函数和成员变量 ...
  };
  
  void someFunction(MyClass obj) {
      // ... 函数实现 ...
  }
  
  int main() {
      someFunction(42); // 隐式转换，可能不是预期的
      return 0;
  }
  
  
  在上面的代码中，当调用someFunction(42)时，int到MyClass的隐式转换是允许的，因为存在接受int参数的构造函数。这可能不是你想要的，尤其是当这样的转换可能导致逻辑错误时。
  
  通过将构造函数标记为explicit，可以防止这种隐式转换：
  
  class MyClass {
  public:
      explicit MyClass(int value) {
          // ... 构造函数实现 ...
      }
  
      // 其他成员函数和成员变量 ...
  };
  
  void someFunction(MyClass obj) {
      // ... 函数实现 ...
  }
  
  int main() {
      someFunction(MyClass(42)); // 显式转换，更清晰且不易出错
      // someFunction(42); // 这行代码现在会编译错误，因为不允许隐式转换
      return 0;
  }
  
  在修改后的代码中，MyClass的构造函数被标记为explicit，因此someFunction(42)现在会导致编译错误，因为不允许从int到MyClass的隐式转换。为了调用someFunction，你必须显式地创建一个MyClass对象，如someFunction(MyClass(42))。
  ```

  

* 在C++中，操作符重载（Operator Overloading）是一种特殊的函数，它允许程序员重新定义或重载大部分C++内建操作符的行为，以便它们可以用于用户自定义类型。通过操作符重载，我们可以使自定义类型的操作更加直观和自然，类似于使用内建类型的操作。

  操作符重载是通过在类定义中创建特殊类型的成员函数或非成员函数来实现的。这些函数使用关键字operator后跟要重载的操作符符号或名称来命名。

  下面是一些操作符重载的基本规则和示例：

  * 成员函数操作符重载：当操作符需要一个操作数作为它的类类型的对象，并且另一个操作数是该类的另一个对象或内置类型时，通常将该操作符定义为类的成员函数。

    ```c++
    class Complex {
    public:
        Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}
    
        // 重载加法操作符作为成员函数
        Complex operator+(const Complex& rhs) const {
            return Complex(real + rhs.real, imag + rhs.imag);
        }
    
    private:
        double real, imag;
    };
    
    int main() {
        Complex c1(1, 2), c2(3, 4), c3;
        c3 = c1 + c2; // 使用重载的+操作符
        return 0;
    }
    ```

  * 非成员函数操作符重载：当操作符需要两个操作数，并且它们都是自定义类型的对象时，通常将该操作符定义为非成员函数。

    ```c++
    class Complex {
    public:
        Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}
    
        // ... 其他成员函数 ...
    
        // 获取实部和虚部的函数，用于非成员函数操作符重载
        double getReal() const { return real; }
        double getImag() const { return imag; }
    
    private:
        double real, imag;
    
        // 友元函数声明，允许它们访问类的私有成员
        friend Complex operator+(const Complex& lhs, const Complex& rhs);
    };
    
    // 重载加法操作符作为非成员函数
    Complex operator+(const Complex& lhs, const Complex& rhs) {
        return Complex(lhs.getReal() + rhs.getReal(), lhs.getImag() + rhs.getImag());
    }
    
    int main() {
        Complex c1(1, 2), c2(3, 4), c3;
        c3 = c1 + c2; // 使用重载的+操作符
        return 0;
    }
    ```

  * 重载一元操作符：一元操作符（如+, -, *, &等）通常重载为成员函数，因为它们只需要一个操作数。

    ```c++
    class MyNumber {
    public:
        MyNumber(int val) : value(val) {}
    
        // 重载一元-操作符
        MyNumber operator-() const {
            return MyNumber(-value);
        }
    
    private:
        int value;
    };
    
    int main() {
        MyNumber num(5);
        MyNumber negNum = -num; // 使用重载的一元-操作符
        return 0;
    }
    ```

  注意事项

   * 不是所有的操作符都可以被重载。例如，.、.*、::、sizeof、?:等操作符不能被重载。
   * 重载操作符时，必须保证操作符的语义与其原始意义保持一致或相关，否则会导致代码难以理解和维护。
   * 重载操作符时，不应改变操作符的优先级和结合性。
   * 重载操作符的函数通常应为const成员函数（如果它们不修改对象状态的话），以便它们可以用于常量对象。
   * 重载操作符时，应谨慎考虑是否确实需要重载，以及重载后是否能为代码带来清晰度和便利。有时，简单的成员函数或命名函数可能更易于理解和使用。

* C++标准库提供了几种不同类型的智能指针，每种都有其特定的用途：

  * std::unique_ptr

    std::unique_ptr代表对动态分配对象的独占所有权。在任意时刻，一个对象只能由一个unique_ptr拥有。当unique_ptr被销毁（例如离开其作用域）时，它所指向的对象也会被自动删除。这种智能指针非常适合用于管理单个对象的生命周期。

    ```c++
    std::unique_ptr<int> ptr(new int(5));
    // 使用ptr，例如：*ptr = 10;
    // 当ptr离开作用域时，它会自动删除所指向的int对象
    ```

  * std::shared_ptr

    std::shared_ptr实现共享所有权的智能指针，允许多个shared_ptr实例指向同一个对象。每个shared_ptr维护一个引用计数，当最后一个指向对象的shared_ptr被销毁或重置时，对象才会被删除。这种智能指针适合用于多个所有者共享同一个对象的场景。

    ```c++
    std::shared_ptr<int> ptr1(new int(5));
    std::shared_ptr<int> ptr2 = ptr1; // 引用计数增加
    // 当ptr1和ptr2都离开作用域时，它们所指向的int对象才会被删除
    ```

  * std::weak_ptr

    std::weak_ptr是对std::shared_ptr所管理对象的一种弱引用，它不会控制对象的生命周期。weak_ptr主要用于解决shared_ptr之间循环引用的问题，防止内存无法被正确释放。weak_ptr不拥有所指向的对象，因此不能用来直接访问对象，但可以转换为shared_ptr以临时访问对象。

    ```c++
    std::shared_ptr<int> ptr(new int(5));
    std::weak_ptr<int> wptr = ptr;
    // 使用时，需要将weak_ptr转换为shared_ptr
    if (auto sptr = wptr.lock()) {
        // 如果shared_ptr还存在，可以通过sptr访问对象
    }
    ```

  * 从C++14开始，std::make_unique被引入作为创建unique_ptr的推荐方式，因为它比直接使用new更安全，更易于使用，并且性能通常更好。同样，std::make_shared用于创建shared_ptr，它可以同时分配控制块和所管理的对象，从而可能减少内存分配次数。

    ```c++
    // 使用 std::make_unique 创建 std::unique_ptr  
        auto ptr = std::make_unique<int>(42);
    // 使用 std::make_shared 创建 std::shared_ptr  
        auto sharedPtr = std::make_shared<int>(42);  
    ```

    

* C++错误处理

  1. 异常处理

     C++的异常处理机制使用try、catch和throw关键字。当程序遇到异常情况时，可以使用throw抛出异常，然后在catch块中捕获并处理它。

     ```c++
     #include <iostream>
     #include <stdexcept> // 包含标准异常类
     
     int main() {
         try {
             // 可能会抛出异常的代码
             throw std::runtime_error("An error occurred");
         } catch (const std::runtime_error& e) {
             // 处理runtime_error异常
             std::cerr << "Caught an exception: " << e.what() << std::endl;
         } catch (...) {
             // 处理所有其他类型的异常
             std::cerr << "Caught an unknown exception" << std::endl;
         }
         return 0;
     }
     ```

     注意：使用异常处理时，应避免在析构函数、构造函数以及资源管理类（如智能指针）中抛出异常，因为这可能导致资源泄露或程序不稳定。

  2. 错误码和错误状态

     另一种常见的错误处理方法是使用错误码或错误状态。函数或方法在执行过程中如果遇到错误，可以返回一个特殊的值或设置错误状态，调用方可以检查这些值或状态来决定如何处理错误。

     ```c++
     enum class ErrorCode {
         SUCCESS,
         INVALID_ARGUMENT,
         OUT_OF_RANGE
     };
     
     ErrorCode divide(int a, int b, int& result) {
         if (b == 0) {
             return ErrorCode::INVALID_ARGUMENT;
         }
         result = a / b;
         return ErrorCode::SUCCESS;
     }
     
     int main() {
         int result;
         ErrorCode code = divide(10, 0, result);
         if (code != ErrorCode::SUCCESS) {
             std::cerr << "Error occurred: " << static_cast<int>(code) << std::endl;
             return 1;
         }
         std::cout << "Result: " << result << std::endl;
         return 0;
     }
     ```

  3. 断言（Assertions）

     断言用于在调试阶段捕获程序中的逻辑错误。它们通过assert宏实现，如果断言的条件不满足（即条件为假），程序将在调试模式下终止，并显示一条错误消息。断言不应用于处理可能由用户输入或外部条件引起的错误，而仅用于验证程序内部的逻辑正确性。

     ```c++
     #include <cassert>
     
     void someFunction(int value) {
         assert(value > 0 && "Value must be positive");
         // ... 其他代码
     }
     ```

     

* 在C++中，lambda表达式（也称为匿名函数）是一种定义简短、内联函数对象的方式。lambda表达式允许我们创建一个匿名函数对象，该对象可以捕获其所在作用域中的变量，并可以在需要的地方被调用。lambda表达式在C++11及以后的版本中可用，并且它们为函数式编程提供了强大的支持。

  下面是lambda表达式的基本语法：

  ```c++
  [capture](parameters) -> return_type { body_of_lambda }
  ```

  capture：捕获子句，用于指定lambda表达式可以访问的外部变量。它可以包括变量按值捕获（[x] 或 [=]）或按引用捕获（[&x] 或 [&]）。关于捕获子句，有几种常见的形式：

  * []：不捕获任何外部变量。
  * [=]：按值捕获所有外部变量。
  * [&]：按引用捕获所有外部变量。
  * [x, &y]：按值捕获x，按引用捕获y。parameters：lambda函数的参数列表，类似于常规函数的参数列表。

  return_type：返回类型，如果省略，则编译器会自动推断返回类型（类似于auto关键字）。
  body_of_lambda：lambda函数的主体，包含要执行的代码。

  ```c++
  #include <iostream>
  #include <vector>
  #include <algorithm>
  
  int main() {
      std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  
      // 使用lambda表达式作为谓词来过滤偶数
      std::vector<int> even_numbers;
      std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(even_numbers),
                    [](int n) { return n % 2 == 0; });
  
      // 输出偶数
      for (int num : even_numbers) {
          std::cout << num << ' ';
      }
      std::cout << std::endl;
  
      return 0;
  }
  ```

  

* 在C++中，函数后面的 -> 符号通常出现在lambda表达式中，用来指定lambda的返回类型。这被称为尾置返回类型（trailing return type）。在C++11及以后的版本中，尾置返回类型特别有用，特别是当lambda的返回类型不容易从返回表达式推断出来时。

  例如，考虑一个lambda表达式，它根据输入的整数是偶数还是奇数返回不同的类型：

  ```c++
  // std::conditional 是一个模板，它根据给定的条件（在这里是 x % 2 == 0）在两个类型之间选择。如果 x 是偶数，则lambda返回 std::string 类型；如果 x 是奇数，则返回 int 类型。尾置返回类型 -> std::conditional<x % 2 == 0, std::string, int>::type 允许我们明确指定lambda的返回类型。
  
  // 需要注意的是，x % 2 == 0 在这里只是用于演示，实际上它不能在尾置返回类型中使用，因为尾置返回类型中的表达式必须在编译时是可评估的。在真实场景中，你可能会使用模板参数或其他编译时常量来决定返回类型。
  
  // 通常情况下，如果lambda的返回类型可以从其返回语句中直接推断出来，你不需要显式指定尾置返回类型。
  auto lambda = [](int x) -> std::conditional<x % 2 == 0, std::string, int>::type {
      if (x % 2 == 0) {
          return "Even";
      } else {
          return x * x;
      }
  };
  ```

  

* 在C++中，decltype是一个类型推导关键字，它用于在编译时查询表达式的类型或变量的类型。decltype可以提供一种方式来获得表达式的类型，以便你可以在后续的代码中使用这个类型，而不需要显式地指定它。

  decltype的主要用途之一是在模板元编程和泛型编程中，以及在自动推导lambda表达式的返回类型时。

  这里有一些decltype的基本用法示例：

  ```c++
  int x = 42;
  decltype(x) y = x; // y的类型是int，并且y被初始化为x的值
  
  const int& foo();
  decltype(foo()) bar = foo(); // bar的类型是const int&
  
  int arr[5];
  decltype(arr) another_arr; // another_arr的类型是int[5]
  
  // 对于表达式
  int a = 3, b = 4;
  decltype(a + b) sum = a + b; // sum的类型是int，因为a + b的结果是int
  
  // 用于推导lambda表达式的返回类型
  auto lambda = [](int x) -> decltype(auto) { return x * 2; };
  // 这里decltype(auto)用于推导返回类型，与直接写-> int效果相同，但更通用
  
  // 使用decltype与auto结合，实现完美转发
  template<typename T>
  void wrapper(T&& arg) {
      foo(std::forward<decltype(arg)>(arg)); // 使用decltype和std::forward实现完美转发
  }
  ```

  在上面的例子中，decltype用于推导变量y、bar、another_arr和sum的类型，以及用于推导lambda表达式的返回类型。在最后一个例子中，decltype与auto和std::forward结合使用，实现了完美转发，允许将参数无损地传递给另一个函数。

  注意，当decltype用于一个未加括号的表达式时，它会得到表达式的类型，包括引用和顶层const。但是，如果表达式被括号包围，decltype会忽略引用和顶层const（顶层const指的是直接修饰变量本身的const，而不是修饰指针、引用或类型内部的const，用来说明指针或引用所指向的对象的内容是不可变的，顶层const在变量赋值和函数参数传递时可能会被忽略）。例如：

  ```c++
  const int& ref = x;
  decltype(ref) a = x; // a的类型是const int&
  decltype((ref)) b = x; // b的类型是const int，注意括号
  ```

  

* 在C++中，std::move是一个用于将左值（lvalue）转换为右值（rvalue）引用的实用工具。这样做的主要目的是允许我们利用移动语义（move semantics）来避免不必要的资源复制，从而提高代码的性能。当对象拥有一些资源（如动态分配的内存、文件句柄等）时，移动语义尤其有用，因为它允许我们将这些资源的所有权从一个对象转移到另一个对象，而不是复制它们。

  std::move本身并不执行任何资源的移动；它只是返回一个右值引用，从而允许编译器选择移动构造函数或移动赋值运算符（如果可用的话）。实际上移动资源的是这些特殊的成员函数。

  下面是std::move的一些基本用法：

  1. 移动构造函数和移动赋值运算符

     ```c++
     #include <iostream>
     #include <string>
     #include <utility> // for std::move
     
     class MyString {
     public:
         MyString(const std::string& s) : data(new std::string(s)) {}
         // 移动构造函数
         MyString(MyString&& other) noexcept : data(other.data) {
             other.data = nullptr;
         }
         // 移动赋值运算符
         MyString& operator=(MyString&& other) noexcept {
             if (this != &other) {
                 delete data;
                 data = other.data;
                 other.data = nullptr;
             }
             return *this;
         }
         // 析构函数
         ~MyString() {
             delete data;
         }
         // 输出字符串内容
         void print() const {
             if (data) {
                 std::cout << *data << std::endl;
             } else {
                 std::cout << "Empty MyString" << std::endl;
             }
         }
     
     private:
         std::string* data;
     };
     
     int main() {
         MyString s1("Hello");
         MyString s2 = std::move(s1); // 使用移动构造函数
         s1.print(); // 输出 "Empty MyString"，因为s1的资源已被移动
         s2.print(); // 输出 "Hello"
     
         MyString s3("World");
         s3 = std::move(s2); // 使用移动赋值运算符
         s2.print(); // 输出 "Empty MyString"，因为s2的资源已被移动
         s3.print(); // 输出 "Hello"
     
         return 0;
     }
     ```

  2. 在模板函数中使用完美转发：在模板函数中，&&与decltype(auto)和std::forward一起使用，可以实现完美转发（Perfect Forwarding）。完美转发允许函数模板将其参数无损地转发给其他函数，保留参数的原始值类别（lvalue或rvalue）。

     ```c++
     template<typename T>
     void wrapper(T&& arg) {
         foo(std::forward<T>(arg)); // 使用std::forward完美转发参数arg
     }
     ```

     在上面的代码中，T&&是一个转发引用，它可以绑定到lvalue或rvalue。std::forward则根据T的类型（是lvalue引用还是rvalue引用）来正确转发参数

     ```c++
     template<typename T>
     void wrapper(T&& arg) {
         process(std::forward<T>(arg)); // 使用std::forward完美转发参数arg
     }
     
     void process(const MyString& str) {
         str.print();
     }
     
     void process(MyString&& str) {
         // 可以在这里执行一些只在移动时才需要的操作
         str.print();
     }
     
     int main() {
         MyString s("Test");
         wrapper(s); // 调用process(const MyString&)
         wrapper(std::move(s)); // 调用process(MyString&&)
         return 0;
     }
     ```

     

* 在C++中，Variadic Templates（可变参数模板）是一种模板机制，允许你为函数或类定义接受可变数量参数的模板。这对于实现泛型编程非常有用，尤其是当你需要处理不同数量或类型的参数时。

  Variadic Templates主要依赖于两个关键字：template<typename... Args>和pack expansion语法。

  Variadic 函数模板：Variadic 函数模板允许你定义接受任意数量参数的函数。

  ```c++
  template<typename... Args>
  void print(Args... args) {
      (std::cout << ... << args) << std::endl;
  }
  
  int main() {
    // print 函数接受任意数量和类型的参数，并使用C++17的折叠表达式（fold expression）来打印它们。
      print("Hello, ");
      print("Hello, ", "world!");
      print(1, 2, 3, 4, 5);
      return 0;
  }
  ```

  Variadic 类模板：Variadic 类模板允许你定义接受任意数量模板参数的类。

  ```c++
  template<typename... Types>
  class Tuple {
  public:
      Tuple(Types... args) : values_{args...} {}
  
      // ... 其他成员函数，如访问、修改元素等 ...
  
  private:
      std::tuple<Types...> values_;
  };
  
  int main() {
    // Tuple 类模板接受任意数量的类型作为模板参数，并使用std::tuple来存储这些类型的值。
      Tuple<int, double, std::string> t(1, 3.14, "Hello");
      // 使用std::get来访问元素或进行其他操作
      return 0;
  }
  ```

  递归展开：在处理Variadic Templates时，经常需要递归地展开参数包。这通常涉及到特化和递归模板函数或类。

  ```c++
  // print_all 函数有两个模板定义：一个接受一个参数和一个参数包，另一个只接受一个参数。当调用print_all时，编译器会递归地调用第一个版本，直到只剩下一个参数，然后调用第二个版本来终止递归。
  template<typename T, typename... Args>
  void print_all(T value, Args... args) {
      std::cout << value << " ";
      print_all(args...); // 递归调用，直到参数包为空
  }
  
  template<typename T>
  void print_all(T value) {
      std::cout << value << std::endl; // 终止递归
  }
  
  int main() {
      print_all(1, "two", 3.0); // 输出: 1 two 3.0
      return 0;
  }
  ```

  

* C++的virtual关键字

  * 纯虚函数是一个在基类中声明但没有定义的虚函数，它需要在派生类中被实现。含有纯虚函数的类被称为抽象类，它不能被实例化。纯虚函数使用 = 0 语法来声明。

    ```c++
    class AbstractBase {
    public:
        virtual void pureVirtualFunction() = 0; // 纯虚函数
    };
    
    class Derived : public AbstractBase {
    public:
        void pureVirtualFunction() override {
            std::cout << "Derived::pureVirtualFunction()" << std::endl;
        }
    };
    
    int main() {
        // AbstractBase* abstractPtr = new AbstractBase(); // 错误！AbstractBase 是抽象类，不能实例化
        Derived* derivedPtr = new Derived();
        derivedPtr->pureVirtualFunction(); // 输出 "Derived::pureVirtualFunction()"
        delete derivedPtr;
        return 0;
    }
    ```

  * 通常不建议在构造函数或析构函数中调用虚函数，因为在构造函数或析构函数执行期间，虚函数不会表现出多态性。

    这意味着在基类的构造函数或析构函数中，如果你调用了一个虚函数，那么实际上调用的是基类中的版本，而不是派生类中可能存在的重写版本。同样地，在派生类的构造函数或析构函数中，如果调用了虚函数，也会调用基类中的版本，直到构造函数链完成或析构函数链开始。

    这个行为的原因是，在构造或析构对象时，对象的完整类型尚未确定或已经不再确定。在构造函数执行期间，对象还在建设中，因此它的最终类型（即它是否是一个派生类对象）尚未可知。类似地，在析构函数执行期间，对象正在被销毁，它的类型信息不再重要。

    ```c++
    #include <iostream>
    
    class Base {
    public:
        Base() {
            foo(); // 调用Base类的foo()
        }
        virtual ~Base() {}
    
        virtual void foo() {
            std::cout << "Base::foo()" << std::endl;
        }
    };
    
    class Derived : public Base {
    public:
        Derived() : Base() {
            foo(); // 仍然调用Base类的foo()，而不是Derived类的版本
        }
        ~Derived() override {}
    
        void foo() override {
            std::cout << "Derived::foo()" << std::endl;
        }
    };
    
    int main() {
        Derived d; // 输出 "Base::foo()" 两次
        return 0;
    }
    ```

  * 虚析构函数（Virtual Destructor）是一种特殊的析构函数，它允许通过基类指针或引用来正确地销毁派生类对象。当基类的析构函数被声明为虚函数时，无论指针或引用的实际类型是什么（基类或派生类），它都会调用正确类型的析构函数。

    虚析构函数对于多态性至关重要，因为它确保了资源的正确释放和避免内存泄漏。如果没有虚析构函数，当使用基类指针指向派生类对象并删除该指针时，只会调用基类的析构函数，而派生类的析构函数不会被调用，这可能导致派生类部分中的资源（如动态分配的内存、文件句柄等）没有被正确释放。

    ```c++
    #include <iostream>
    
    class Base {
    public:
        Base() {
            std::cout << "Base constructor" << std::endl;
        }
    
      // 如果没有将 Base 的析构函数声明为虚函数，那么 delete basePtr; 只会调用 Base 类的析构函数，从而导致 Derived 类部分可能存在的资源泄漏。因此，当基类作为多态类型的基类使用时，通常建议将基类的析构函数声明为虚函数。
        virtual ~Base() { // 虚析构函数
            std::cout << "Base destructor" << std::endl;
        }
    };
    
    class Derived : public Base {
    public:
        Derived() {
            std::cout << "Derived constructor" << std::endl;
        }
    
        ~Derived() { // 派生类的析构函数
            std::cout << "Derived destructor" << std::endl;
        }
    };
    
    int main() {
        Base* basePtr = new Derived(); // 基类指针指向派生类对象
        delete basePtr; // 调用Derived的析构函数，然后是Base的析构函数
        return 0;
    }
    ```

* 在C++中，当定义一个派生类时，它会自动继承其基类的所有构造函数（除了默认构造函数和拷贝构造函数）。但是，拷贝构造函数和赋值运算符并不会被自动继承，这意味着如果你想要为派生类实现特定的拷贝语义，你需要显式地定义它们。

  拷贝构造函数是一个特殊的构造函数，用于创建一个新对象作为现有对象的副本。对于派生类，如果你不提供自己的拷贝构造函数，编译器会为你生成一个默认的拷贝构造函数。这个默认的拷贝构造函数会执行成员变量的浅拷贝，包括从基类继承的成员。但是，这通常不是你想要的，特别是当基类或派生类中有动态分配的内存或其他需要特殊处理的资源时。

  类似地，赋值运算符（operator=）用于将一个对象的值赋给另一个对象。如果你不提供自己的赋值运算符，编译器也会为你生成一个默认的。和拷贝构造函数一样，这个默认的赋值运算符也会执行浅拷贝，这可能导致资源泄漏或其他问题。

  对于派生类，如果你想要实现深拷贝或特殊的赋值行为，你应该显式地定义拷贝构造函数和赋值运算符。

  ```c++
  #include <iostream>
  #include <cstring>
  
  class Base {
  public:
      Base(const char* data) : m_data(new char[strlen(data) + 1]) {
          strcpy(m_data, data);
      }
  
      // 基类的拷贝构造函数
      Base(const Base& other) : m_data(new char[strlen(other.m_data) + 1]) {
          strcpy(m_data, other.m_data);
      }
  
      // 基类的赋值运算符
      Base& operator=(const Base& other) {
          if (this != &other) {
              delete[] m_data;
              m_data = new char[strlen(other.m_data) + 1];
              strcpy(m_data, other.m_data);
          }
          return *this;
      }
  
      ~Base() {
          delete[] m_data;
      }
  
  private:
      char* m_data;
  };
  
  // 在派生类的拷贝构造函数和赋值运算符中，我们显式地调用了基类的相应函数，以确保基类部分的正确拷贝和赋值。这是实现深拷贝和正确资源管理的重要步骤。
  class Derived : public Base {
  public:
      Derived(const char* baseData, int extra) : Base(baseData), m_extra(extra) {}
  
      // 派生类的拷贝构造函数
      Derived(const Derived& other) : Base(other), m_extra(other.m_extra) {}
  
      // 派生类的赋值运算符
      Derived& operator=(const Derived& other) {
          if (this != &other) {
              Base::operator=(other); // 调用基类的赋值运算符
              m_extra = other.m_extra;
          }
          return *this;
      }
  
  private:
      int m_extra;
  };
  
  int main() {
      Derived d1("Hello", 10);
      Derived d2 = d1; // 调用派生类的拷贝构造函数
      Derived d3;
      d3 = d1; // 调用派生类的赋值运算符
      return 0;
  }
  ```

  

* 在C++中，有时候我们可能想要禁止类对象的拷贝，以防止可能的误用，如拷贝可能导致多个对象拥有相同资源的问题，从而导致资源泄露或数据不一致。为了禁止拷贝，我们可以将拷贝构造函数和赋值运算符声明为delete。

  从C++11开始，我们可以使用= delete语法来明确地删除成员函数，包括拷贝构造函数和赋值运算符。这样做会告诉编译器这些函数是不可用的，并尝试使用它们会导致编译错误。

  ```c++
  class NonCopyable {
  public:
      NonCopyable() = default;
      ~NonCopyable() = default;
  
      // 删除拷贝构造函数
      NonCopyable(const NonCopyable&) = delete;
  
      // 删除赋值运算符
      NonCopyable& operator=(const NonCopyable&) = delete;
  
      // 其他成员函数...
  };
  ```

  注意，当你想要禁止拷贝但允许移动时，你可以只删除拷贝构造函数和赋值运算符，同时提供移动构造函数和移动赋值运算符。这样，对象仍然可以被移动而不是被拷贝：

  ```c++
  class MovableOnly {
  public:
      MovableOnly() = default;
      ~MovableOnly() = default;
  
      // 删除拷贝构造函数和赋值运算符
      MovableOnly(const MovableOnly&) = delete;
      MovableOnly& operator=(const MovableOnly&) = delete;
  
      // 提供移动构造函数
      MovableOnly(MovableOnly&& other) noexcept {
          // 移动资源的代码...
      }
  
      // 提供移动赋值运算符
      MovableOnly& operator=(MovableOnly&& other) noexcept {
          if (this != &other) {
              // 移动资源的代码...
          }
          return *this;
      }
  
      // 其他成员函数...
  };
  ```

  在这个MovableOnly类的例子中，我们提供了移动构造函数和移动赋值运算符，同时删除了拷贝构造函数和赋值运算符，以允许对象被移动但禁止被拷贝。注意，移动构造函数和移动赋值运算符通常被标记为noexcept，以表明它们不会抛出异常，这对于某些库函数（如std::vector）来说是必要的，因为它们需要保证在移动操作失败时不会造成资源泄露。

* 在C++中，有四种类型转换操作符，它们允许你显式地将一种类型的对象或值转换为另一种类型。

  1. static_cast

     static_cast是最常见且最安全的类型转换操作符。它用于在数值类型之间、非多态类型之间、void指针和其他非函数指针之间、对象指针和void指针之间进行转换，以及添加或删除const或volatile限定符。它不会在运行时进行检查，因此在使用它之前确保转换是有效的很重要。

     ```c++
     double d = 3.14;
     int i = static_cast<int>(d); // i将会是3，但会损失精度
     ```

  2. dynamic_cast

     dynamic_cast用于在具有虚函数的类层次结构中进行安全的向下转型。它主要用于处理多态类型的对象，在运行时检查转换是否合法。如果转换不可能成功，dynamic_cast会返回空指针（对于指针类型）或抛出异常（对于引用类型）。

     ```c++
     class Base {
     public:
         virtual ~Base() {}
     };
     
     class Derived : public Base {
     };
     
     Base* basePtr = new Derived;
     Derived* derivedPtr = dynamic_cast<Derived*>(basePtr); // 安全的向下转型
     if (derivedPtr) {
         // 转型成功，可以使用derivedPtr
     } else {
         // 转型失败
     }
     ```

  3. const_cast

     const_cast用于添加或删除对象的常量性。它可以用来将常量对象转换为非常量对象（反之亦然），但这并不会改变对象的实际常量性；它只是告诉编译器忽略常量性。因此，使用const_cast时必须格外小心，以避免修改实际上应该是常量的对象。

     ```c++
     const int a = 10;
     int* p = const_cast<int*>(&a); // 移除const限定符，但不应修改a的值
     // *p = 20; // 这会导致未定义行为，因为a是常量
     ```

  4.  reinterpret_cast

     reinterpret_cast提供了最低级别的转换，它重新解释位模式。它允许将任何指针类型转换为任何其他指针类型，将整数转换为指针，将函数指针转换为任意其他指针类型等。这种转换通常是非常危险的，因为它几乎不执行任何类型检查，并且可能导致未定义行为。因此，除非在特定情况下确实需要，否则应避免使用reinterpret_cast。

     ```c++
     int i = 42;
     char* p = reinterpret_cast<char*>(&i); // 将int指针转换为char指针
     ```

     