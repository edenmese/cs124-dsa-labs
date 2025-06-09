//
//  'notes'.hpp
//  Hashtable
//
//  Created by Eden Meseret on 4/11/24.
//

#ifndef _notes__hpp
#define _notes__hpp

/*These are my notes on the lab of everything i've changed

 - TaskMenu init()
    - added a user input prompt to get filename from user
    - file handling code within a 'try' block to catch potential exceptions
    - added error handling for file opening:
            a)checked if the file could be opened successfully using 'is_open()'
            b)if file can't open, implemented thow_at_runtime error
    - error handling for file reading and parsing within 'try block'
            a) 'try-catch' to handle the exceptions that may occur with file reaading and parsing
            b) display error message using 'cerr' if exception is caught
 

 
 
 
 
 
 
 
 
 
 
 
 for later (extra credit):
 try catch for the date





#endif /* _notes__hpp */
