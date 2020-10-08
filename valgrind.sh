#!/bin/bash

valgrind --leak-check=full test_put                                            
                                                                               
valgrind --leak-check=full test_concat

valgrind --leak-check=full test_close

valgrind --leak-check=full test_remove

valgrind --leak-check=full test_search

valgrind --leak-check=full test_open

valgrind --leak-check=full test_get