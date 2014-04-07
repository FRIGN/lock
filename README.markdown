Lock
====

This program creates a lock directory to ensure two programs do no simulaneously execute

example:

    calvin@barnabas:~/lock$ lock p
    calvin@barnabas:~/lock$ lock p && echo 'UNLOCKED' &
    [2] 22844
    calvin@barnabas:~/lock$ rmdir p
    * two seconds later *
    calvin@barnabas:~/lock$ 
    UNLOCKED
    [2]-  Done                    lock p && echo -e '\nUNLOCKED\n'
    calvin@barnabas:~/lock$ 
