#include <easings.hh>
#include <iostream>

int main( ) {
    auto easer = easings::c_easer< int >( 0.f, 100, 5.f, easings::ease_in_out_quad );
    while( !easer.is_done( ) ) {
        std::cout << easer.get_value( ) << std::endl;
    }

    std::cout << "end value: " << easer.get_value( ) << std::endl;
}