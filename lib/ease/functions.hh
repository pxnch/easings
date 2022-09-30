#ifndef EASINGS_FUNCTIONS_HH
#define EASINGS_FUNCTIONS_HH

#include <functional>

namespace easings {
    enum e_easing_type {
        ease_in_sine,
        ease_out_sine,
        ease_in_out_sine,
        ease_in_quad,
        ease_out_quad,
        ease_in_out_quad,
        ease_in_cubic,
        ease_out_cubic,
        ease_in_out_cubic,
        ease_in_quart,
        ease_out_quart,
        ease_in_out_quart,
        ease_in_quint,
        ease_out_quint,
        ease_in_out_quint,
        ease_in_expo,
        ease_out_expo,
        ease_in_out_expo,
        ease_in_circ,
        ease_out_circ,
        ease_in_out_circ,
        ease_in_back,
        ease_out_back,
        ease_in_out_back,
        ease_in_elastic,
        ease_out_elastic,
        ease_in_out_elastic,
        ease_in_bounce,
        ease_out_bounce,
        ease_in_out_bounce
    };

    namespace internal {
        inline constexpr double m_pi = 3.14159265358979323846;
    }

    inline const std::function< double( double ) > &get_ease( e_easing_type easing_type ) {
        switch ( easing_type ) {
            case e_easing_type::ease_in_sine: {
                static const std::function< double( double ) > ease_in_sine = [ ]( double t ) -> double {
                    return 1.0 - std::cos( ( t * internal::m_pi ) / 2.0 );
                };
                return ease_in_sine;
            }
            case e_easing_type::ease_out_sine: {
                static const std::function< double( double ) > ease_out_sine = [ ]( double t ) -> double {
                    return std::sin( ( t * internal::m_pi ) / 2.0 );
                };
                return ease_out_sine;
            }
            case e_easing_type::ease_in_out_sine: {
                static const std::function< double( double ) > ease_in_out_sine = [ ]( double t ) -> double {
                    return -( std::cos( internal::m_pi * t ) - 1.0 ) / 2.0;
                };
                return ease_in_out_sine;
            }
            case e_easing_type::ease_in_quad: {
                static const std::function< double( double ) > ease_in_quad = [ ]( double t ) -> double {
                    return t * t;
                };
                return ease_in_quad;
            }
            case e_easing_type::ease_out_quad: {
                static const std::function< double( double ) > ease_out_quad = [ ]( double t ) -> double {
                    return t * ( 2.0 - t );
                };
                return ease_out_quad;
            }
            case e_easing_type::ease_in_out_quad: {
                static const std::function< double( double ) > ease_in_out_quad = [ ]( double t ) -> double {
                    return t < 0.5 ? 2.0 * t * t : -1.0 + ( 4.0 - 2.0 * t ) * t;
                };
                return ease_in_out_quad;
            }
            case e_easing_type::ease_in_cubic: {
                static const std::function< double( double ) > ease_in_cubic = [ ]( double t ) -> double {
                    return t * t * t;
                };
                return ease_in_cubic;
            }
            case e_easing_type::ease_out_cubic: {
                static const std::function< double( double ) > ease_out_cubic = [ ]( double t ) -> double {
                    return ( --t ) * t * t + 1.0;
                };
                return ease_out_cubic;
            }
            case e_easing_type::ease_in_out_cubic: {
                static const std::function< double( double ) > ease_in_out_cubic = [ ]( double t ) -> double {
                    return t < 0.5 ? 4.0 * t * t * t : ( t - 1.0 ) * ( 2.0 * t - 2.0 ) * ( 2.0 * t - 2.0 ) + 1.0;
                };
                return ease_in_out_cubic;
            }
            case e_easing_type::ease_in_quart: {
                static const std::function< double( double ) > ease_in_quart = [ ]( double t ) -> double {
                    return t * t * t * t;
                };
                return ease_in_quart;
            }
            case e_easing_type::ease_out_quart: {
                static const std::function< double( double ) > ease_out_quart = [ ]( double t ) -> double {
                    return 1.0 - ( --t ) * t * t * t;
                };
                return ease_out_quart;
            }
            case e_easing_type::ease_in_out_quart: {
                static const std::function< double( double ) > ease_in_out_quart = [ ]( double t ) -> double {
                    return t < 0.5 ? 8.0 * t * t * t * t : 1.0 - 8.0 * ( --t ) * t * t * t;
                };
                return ease_in_out_quart;
            }
            case e_easing_type::ease_in_quint: {
                static const std::function< double( double ) > ease_in_quint = [ ]( double t ) -> double {
                    return t * t * t * t * t;
                };
                return ease_in_quint;
            }
            case e_easing_type::ease_out_quint: {
                static const std::function< double( double ) > ease_out_quint = [ ]( double t ) -> double {
                    return 1.0 + ( --t ) * t * t * t * t;
                };
                return ease_out_quint;
            }
            case e_easing_type::ease_in_out_quint: {
                static const std::function< double( double ) > ease_in_out_quint = [ ]( double t ) -> double {
                    return t < 0.5 ? 16.0 * t * t * t * t * t : 1.0 + 16.0 * ( --t ) * t * t * t * t;
                };
                return ease_in_out_quint;
            }

            case e_easing_type::ease_in_expo: {
                static const std::function< double( double ) > ease_in_expo = [ ]( double t ) -> double {
                    return t == 0.0 ? 0.0 : std::pow( 2.0, 10.0 * t - 10.0 );
                };
                return ease_in_expo;
            }
            case e_easing_type::ease_out_expo: {
                static const std::function< double( double ) > ease_out_expo = [ ]( double t ) -> double {
                    return t == 1.0 ? 1.0 : 1.0 - std::pow( 2.0, -10.0 * t );
                };
                return ease_out_expo;
            }
            case e_easing_type::ease_in_out_expo: {
                static const std::function< double( double ) > ease_in_out_expo = [ ]( double t ) -> double {
                    if ( t == 0.0 || t == 1.0 ) {
                        return t;
                    }

                    if ( t < 0.5 ) {
                        return 0.5 * std::pow( 2.0, ( 20.0 * t ) - 10.0 );
                    }

                    return -0.5 * std::pow( 2.0, ( -20.0 * t ) + 10.0 ) + 1.0;
                };
                return ease_in_out_expo;
            }

            case e_easing_type::ease_in_circ: {
                static const std::function< double( double ) > ease_in_circ = [ ]( double t ) -> double {
                    return 1.0 - std::sqrt( 1.0 - ( t * t ) );
                };
                return ease_in_circ;
            }
            case e_easing_type::ease_out_circ: {
                static const std::function< double( double ) > ease_out_circ = [ ]( double t ) -> double {
                    return std::sqrt( 1.0 - ( --t ) * t );
                };
                return ease_out_circ;
            }
            case e_easing_type::ease_in_out_circ: {
                static const std::function< double( double ) > ease_in_out_circ = [ ]( double t ) -> double {
                    return t < 0.5 ? ( 1.0 - std::sqrt( 1.0 - 4.0 * ( t * t ) ) ) * 0.5 :
                           ( std::sqrt( 1.0 - ( -2.0 * t + 2.0 ) * ( -2.0 * t + 2.0 ) ) + 1.0 ) * 0.5;
                };
                return ease_in_out_circ;
            }

            case e_easing_type::ease_in_elastic: {
                static const std::function< double( double ) > ease_in_elastic = [ ]( double t ) -> double {
                    return std::sin( 13.0 * ( internal::m_pi / 2.0 ) * t ) * std::pow( 2.0, 10.0 * ( t - 1.0 ) );
                };
                return ease_in_elastic;
            }
            case e_easing_type::ease_out_elastic: {
                static const std::function< double( double ) > ease_out_elastic = [ ]( double t ) -> double {
                    return std::sin( -13.0 * ( internal::m_pi / 2.0 ) * ( t + 1.0 ) ) * std::pow( 2.0, -10.0 * t ) +
                           1.0;
                };
                return ease_out_elastic;
            }
            case e_easing_type::ease_in_out_elastic: {
                static const std::function< double( double ) > ease_in_out_elastic = [ ]( double t ) -> double {
                    return t < 0.5 ? 0.5 * std::sin( 13.0 * ( internal::m_pi / 2.0 ) * ( 2.0 * t ) ) *
                                     std::pow( 2.0, 10.0 * ( 2.0 * t - 1.0 ) ) : 0.5 * ( std::sin(
                            -13.0 * ( internal::m_pi / 2.0 ) * ( ( 2.0 * t - 1.0 ) + 1.0 ) ) * std::pow( 2.0, -10.0 *
                                                                                                              ( 2.0 *
                                                                                                                t -
                                                                                                                1.0 ) ) +
                                                                                         2.0 );
                };
                return ease_in_out_elastic;
            }

            case e_easing_type::ease_in_back: {
                static const std::function< double( double ) > ease_in_back = [ ]( double t ) -> double {
                    return t * t * t - t * std::sin( t * internal::m_pi );
                };
                return ease_in_back;
            }
            case e_easing_type::ease_out_back: {
                static const std::function< double( double ) > ease_out_back = [ ]( double t ) -> double {
                    return 1.0 + ( --t ) * t * t + t * std::sin( t * internal::m_pi );
                };

                return ease_out_back;
            }

            case e_easing_type::ease_in_out_back: {
                static const std::function< double( double ) > ease_in_out_back = [ ]( double t ) -> double {
                    return t < 0.5 ? ( t * t * t - t * std::sin( t * internal::m_pi ) ) * 0.5 :
                           ( 1.0 + ( --t ) * t * t + t * std::sin( t * internal::m_pi ) ) * 0.5;
                };
                return ease_in_out_back;
            }

            case e_easing_type::ease_in_bounce: {
                static const std::function< double( double ) > ease_in_bounce = [ ]( double t ) -> double {
                    return std::pow( 2.0, 6.0 * ( t - 1.0 ) ) * std::abs( std::sin( t * internal::m_pi * 3.5 ) );
                };
                return ease_in_bounce;
            }

            case e_easing_type::ease_out_bounce: {
                static const std::function< double( double ) > ease_out_bounce = [ ]( double t ) -> double {
                    return 1.0 - std::pow( 2.0, -6.0 * t ) * std::abs( std::cos( t * internal::m_pi * 3.5 ) );
                };
                return ease_out_bounce;
            }

            case e_easing_type::ease_in_out_bounce: {
                static const std::function< double( double ) > ease_in_out_bounce = [ ]( double t ) -> double {
                    return t < 0.5 ? 8.0 * std::pow( 2.0, 8.0 * ( t - 1.0 ) ) *
                                     std::abs( std::sin( t * internal::m_pi * 7.0 ) ) : 1.0 - 8.0 * std::pow( 2.0,
                                                                                                              -8.0 *
                                                                                                              t ) *
                                                                                              std::abs( std::sin( t *
                                                                                                                  internal::m_pi *
                                                                                                                  7.0 ) );
                };
                return ease_in_out_bounce;
            }
        }

        static const std::function< double( double ) > linear = [ ]( double t ) -> double {
            return t;
        };

        return linear;
    }
}


#endif //EASINGS_FUNCTIONS_HH
