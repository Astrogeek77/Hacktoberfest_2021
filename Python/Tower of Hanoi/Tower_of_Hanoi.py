"""
TOWERS OF HANOI IMPLEMENTATION IN PYTHON
"""
def tower_of_hanoi(n, Start, Auxillary, Destination):
    #This statement used to determine how calls are generated in Recursive approach
    if n > 0:
        # First recursive call
        tower_of_hanoi(n - 1, Start, Destination, Auxillary)
        # Moving from Source Rod to Destination Rod 
        if Start[0]!=[]:
            disk = Start[0].pop()
            print("Moving " + str(disk) + " From Sorce- "+Start[1] + " to " + "Destination- "+Destination[1])
            Destination[0].append(disk)
        # Now Second recursion from Auxillary to Destination
        tower_of_hanoi(n - 1, Auxillary, Start, Destination)
        
if __name__=="__main__":
    n=3 # Number of Disks we want 
    Start = [[],"A"]
    Destination = [[],"B"]
    Auxillary = [[],"C"]
    [Start[0].append(x) for x in range(1,n+1)]
    Start[0]=Start[0][::-1]
    tower_of_hanoi(len(Start[0]),Start,Auxillary,Destination)
