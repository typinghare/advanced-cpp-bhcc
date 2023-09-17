# C++ 20
[C++20: An (Almost) Complete Overview - Marc Gregoire - CppCon 2020](https://www.youtube.com/watch?v=FRkJCvHWdwQ)

## Ranges
Ranges provide nice and easier to read syntax:

~~~c++
vector data{11, 12, 13};
sort(begin(data), end(data));   // traditional
ranges::sort(data);             // with ranges
~~~

Example of chaining views:

~~~c++
vector data {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

auto result { data
    | views::filter([](const auto& value) { return value % 2 == 0; })
    | views::transform([](const auto& value) { return value * 2; })
    | views::drop(2)
    | views::reverse
    | views::transform([](int i) { return to_string{i}; })
};
~~~

## Concepts
