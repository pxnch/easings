# easings
This Repository is a header-only library implementing easings.net functions in modern c++ and extending it with an easer class.

# including the library
Just include all files contained in the "lib" folder in your project and include "easings.hh".
All features are accessed trough the "easings" namespace.

# supported easing types

all easing methods from easings.net are supported.
you can specify a type by using "easings::<easing_type>".
the names of the easings can be found [here](https://github.com/pxnch/easings/blob/main/lib/ease/functions.hh).

# getting an easing function
```cpp
auto easing = easings::get_ease( <easing_type> );
double test = easing( 0.5 );
```

# c_easer
This class is meant to be used for easing things over a set period of time with an easing function.

[code example](https://github.com/pxnch/easings/blob/main/example/main.cc)

### usage
```cpp
auto easer = easings::c_easer< type >( start, end, duration, easing type );

type value = easer.get_value( );

easer.direct( value, duration );

bool done = easer.is_done( );
```
### type requirements

- has to have support for the operator **-** (type)
- has to have support for the operator **+** (type)
- has to have support for the operator **\*** (double)

# license
easings is distributed with an MIT License. You can see [LICENSE.md](https://github.com/pxnch/easings/blob/main/LICENSE.md) for more info.

