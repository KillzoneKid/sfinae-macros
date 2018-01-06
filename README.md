## SFINAE Macros

###### **Substitution Failure Is Not An Error**

An example of using `SFINAE` macros I made, which makes enabling and disabling templates based on provided type a bit more humane ;)

More or different `IS_XXXXXX` macros could be made easily by wrapping [type_traits methods](http://en.cppreference.com/w/cpp/header/type_traits) similar those provided in the code example.