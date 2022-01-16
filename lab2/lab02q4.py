import sys

# Constants 
DIRECTION_INCREASING = 1
DIRECTION_SAME = 0
DIRECTION_DECREASING = -1

# Variables in which to store state
lines_read = 0
previous_value = 0
current_start = 0
current_end = 0
current_type = 0
best_start = 0
best_end = 0
best_type = 0


for current_line in sys.stdin:
        lines_read = ( lines_read +1  )
        current_value = int( current_line )

        if lines_read == 1:
                current_start = current_end = 0
                curent_type = DIRECTION_SAME
                best_start = current_start
                best_end = current_end
                best_type = current_type
        else:
                if ( current_type == DIRECTION_INCREASING ):
                        if ( current_value > previous_value ):
                                # Was increasing still increasing
                                current_type == DIRECTION_INCREASING
                                current_end = lines_read
                                pass
                        elif ( current_value == previous_value ):
                                # Was increasing now same
                                current_type = DIRECTION_SAME
                                current_start = lines_read
                                pass
                        elif ( current_value < previous_value ):
                                # Was increasing now decreasing
                                current_type = DIRECTION_DECREASING
                                current_start = lines_read
                                pass
                        else:
                                print( "Mathematics doesn't work this way")

                elif ( current_type == DIRECTION_SAME ):
                        if ( current_value > previous_value ):
                                # Was same now increasing
                                current_type = DIRECTION_INCREASING
                                current_start = lines_read
                                
                                pass
                        elif ( current_value == previous_value ):
                                # Was same still same
                                current_type = DIRECTION_SAME
                                current_end = lines_read
                                pass
                        elif ( current_value < previous_value ):
                                # Was same now decreasing
                                current_type = DIRECTION_DECREASING
                                current_start = lines_read
                                pass
                        else:
                                print( "Mathematics doesn't work this way")
                elif ( current_type == DIRECTION_DECREASING ):
                        if ( current_value > previous_value ):
                                # Was decreasing now increasing
                                current_type = DIRECTION_INCREASING
                                current_start = lines_read
                                pass
                        elif ( current_value == previous_value ):
                                # Was dcreasing now same
                                current_type = DIRECTION_SAME
                                current_start = lines_read
                                pass
                        elif ( current_value < previous_value ):
                                # Was descreasing still decreasing
                                current_type = DIRECTION_DECREASING
                                current_end = lines_read
                                pass
                        else:
                                print( "Mathematics doesn't work this way")
                else:
                        print( "Unknown State!")
        
        
        if (current_end - current_start +1) > (best_end - best_start + 1):
                best_end = current_end
                best_start = current_start
                best_type = curent_type


        previous_value = current_value

length = (best_end - best_start) + 1

if best_type == 1:
        print("start:", best_start, "end:", best_end, "length:", length, "direction: increasing")

elif best_type == 0:
        print("start:", best_start, "end:", best_end, "length:", length, "direction: decreasing")

elif best_type == -1:
        print("start:", best_start, "end:", best_end, "length:", length, "direction: decreasing")
