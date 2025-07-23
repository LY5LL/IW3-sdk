#include "iw3_qlib.h"

#include "iw3_common.h"

int Q_stricmpn ( const char* s1, const char* s2, int n )
{
        int		c1, c2;

        // bk001129 - moved in 1.17 fix not in id codebase
        if ( s1 == NULL ) {
                if ( s2 == NULL )
                        return 0;
                else
                        return -1;
        }
        else if ( s2 == NULL )
                return 1;



        do {
                c1 = *s1++;
                c2 = *s2++;

                if ( !n-- ) {
                        return 0;		// strings are equal until end point
                }

                if ( c1 != c2 ) {
                        if ( c1 >= 'a' && c1 <= 'z' ) {
                                c1 -= ('a' - 'A');
                        }
                        if ( c2 >= 'a' && c2 <= 'z' ) {
                                c2 -= ('a' - 'A');
                        }
                        if ( c1 != c2 ) {
                                return c1 < c2 ? -1 : 1;
                        }
                }
        } while ( c1 );

        return 0;		// strings are equal
}

int Q_stricmp ( const char* s1, const char* s2 )
{
        return (s1 && s2) ? Q_stricmpn ( s1, s2, 99999 ) : -1;
}

int Q_strlen( const char* string )
{
        const char* s;

        s = string;
        while ( *s ) {
                s++;
        }
        return s - string;
}