/*
The Towers of Hanoi is a classic puzzle with 3 pegs and multiple disks of different sizes.
The goal of the puzzle is to move all the disks from the first peg to the third peg according to the following rules :
    a)Only one disk can be moved at a time.
    b)You can only move the top disc in a stack.
    c)No disk may be placed on top of a smaller disk.
Logic
    a)Move a tower of height-1 to the buffer peg, using the destination peg.
    b)Move the remaining disk to the destination peg.
    c)Move the tower of height-1 from the buffer peg to the destination peg using the source peg.
Note-To move n disks, the min number of required steps are 2^n - 1
*/

function stepsToSolveHanoiT(height, srcP, desP, bufferP) {
    if (height >= 1) {
  
      // Move a tower of height-1 to the buffer peg, using the destination peg.
      stepsToSolveHanoiT(height - 1, srcP, bufferP, desP);
  
      // Move the remaining disk to the destination peg.
      console.log('Move disk from Tower ', srcP, ' to Tower ', desP);
  
      // Move the tower of `height-1` from the `buffer peg` to the `destination peg` using the `source peg`.        
      stepsToSolveHanoiT(height - 1, bufferP, desP, srcP);
    }
    
    return;
  }

  stepsToSolveHanoiT(3, "B", "A", "C");``
