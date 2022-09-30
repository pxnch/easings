#ifndef EASINGS_EASER_HH
#define EASINGS_EASER_HH


#include <chrono>

namespace easings {
    // this class is made for having easy and fast options to animate things with low code effort
    // and support for custom types
    template< typename val_t >
    class c_easer {
    public:
        // construct an easer with a given duration and easing function, start and end value
        c_easer( val_t start, val_t end, float duration = 1.f, e_easing_type easing_type = ease_in_out_sine ) {
            m_easing_function = get_ease( easing_type );

            m_start = start;
            m_end = end;

            m_duration = duration;

            m_start_time = std::chrono::steady_clock::now( );
        }

        // get value based on current time progress
        val_t get_value( ) {
            auto current_time = std::chrono::steady_clock::now( );
            auto elapsed_time = std::chrono::duration_cast< std::chrono::duration< float > >(
                    current_time - m_start_time ).count( );

            if ( elapsed_time >= m_duration )
                return m_end;

            auto progress = double( elapsed_time / m_duration );
            double multiplier = m_easing_function( progress );

            return m_start + ( m_end - m_start ) * multiplier;
        }

        bool is_done( ) {
            auto current_time = std::chrono::steady_clock::now( );
            auto elapsed_time = std::chrono::duration_cast< std::chrono::duration< float > >(
                    current_time - m_start_time ).count( );

            return elapsed_time > m_duration;
        }

        // set new end value
        void direct( val_t value, float duration = 1.f ) {
            // only redirect if we don't have the same end value already
            if ( m_end != value ) {
                // start from current value
                m_start = get_value( );

                m_end = value;
                m_start_time = std::chrono::steady_clock::now( );

                m_duration = duration;
            }
        }

    private:
        std::function< double( double ) > m_easing_function;

        val_t m_start, m_end;

        float m_duration;

        std::chrono::steady_clock::time_point m_start_time;
    };
}


#endif //EASINGS_EASER_HH
