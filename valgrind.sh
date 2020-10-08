#!/bin/bash

valgrind --leak-check=full test_put                                            
                                                                                
valgrind --leak-check=full test_concat   
