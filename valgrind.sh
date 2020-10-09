#!/bin/bash

#valgrind --leak-check=full --show-leak-kinds=all test_put

valgrind --leak-check=full --show-leak-kinds=all test_hopen                              
                                                                               
#valgrind --leak-check=full --show-leak-kinds=all test_concat

#valgrind --leak-check=full --show-leak-kinds=all test_close

#valgrind --leak-check=full --show-leak-kinds=all test_remove

#valgrind --leak-check=full --show-leak-kinds=all test_search

#valgrind --leak-check=full --show-leak-kinds=all test_get

#valgrind --leak-check=full --show-leak-kinds=all test_open
