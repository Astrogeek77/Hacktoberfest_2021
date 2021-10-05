//-------------------------------------------Bubble Sort-----------------------------------------------------//

function bubbleSort(arr) {

    //Outer pass
    for (let i = 0; i < arr.length; i++) {

        //Inner pass
        for (let j = 0; j < arr.length - i - 1; j++) {

            //Value comparison using ascending order

            if (arr[j + 1] < arr[j]) {

                //Swapping
                [arr[j + 1], arr[j]] = [arr[j], arr[j + 1]]
            }
        }
    };
    return arr;
};

//-------------------------------------------Selection Sort-----------------------------------------------------//

function selectionSort(arr) {
    let min;

    //start passes.
    for (let i = 0; i < arr.length; i++) {
        //index of the smallest element to be the ith element.
        min = i;

        //Check through the rest of the array for a lesser element
        for (let j = i + 1; j < arr.length; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        //compare the indexes
        if (min !== i) {
            //swap
            [arr[i], arr[min]] = [arr[min], arr[i]];
        }
    }

    return arr;
}

//-------------------------------------------Insertion Sort-----------------------------------------------------//

function insertionSort(arr) {
    //Start from the second element.
    for (let i = 1; i < arr.length; i++) {

        //Go through the elements behind it.
        for (let j = i - 1; j > -1; j--) {

            //value comparison using ascending order.
            if (arr[j + 1] < arr[j]) {

                //swap
                [arr[j + 1], arr[j]] = [arr[j], arr[j + 1]];

            }
        }
    };

    return arr;
}

//-------------------------------------------Merge Sort-----------------------------------------------------//

//merging two arrays appropriately.
function merge(arr1, arr2) {
    //make a new array and have two value pointers
    let res = [],
        i = 0,
        j = 0;

    //sorting the first array.
    if (arr1.length > 1) {
        let min = 0;
        for (let i = 0; i < arr1.length; i++) {
            if (i !== min) {
                if (arr1[i] < arr1[min]) {
                    //also swap the elements
                    [arr1[i], arr1[min]] = [arr1[min], arr1[i]];
                    //change the minimum
                    min = i;
                }
            }
        }
    }

    //sorting the second array.
    if (arr2.length > 1) {
        let min = 0;
        for (let i = 0; i < arr2.length; i++) {
            if (i !== min) {
                if (arr2[i] < arr2[min]) {
                    //also swap the elements
                    [arr2[i], arr2[min]] = [arr2[min], arr2[i]];
                    //change the minimum
                    min = i;
                }
            }
        }
    }

    //Value comparison.
    while (i < arr1.length && j < arr2.length) {
        if (arr1[i] < arr2[j]) {
            res.push(arr1[i]);
            i++;
        } else {
            res.push(arr2[j]);
            j++;
        }
    }

    //pushing the rest of arr1.
    while (i < arr1.length) {
        res.push(arr1[i]);
        i++;
    }

    //pushing the rest of arr2.
    while (j < arr2.length) {
        res.push(arr2[j]);
        j++;
    }

    return res;
}

//merge sort
function mergeSort(arr) {
    //Best case
    if (arr.length <= 1) return arr;

    //splitting into halves
    let mid = Math.ceil(arr.length / 2);

    let arr1 = arr.slice(0, mid);

    let arr2 = arr.slice(mid);

    let arr1_subarrays = [],
        sorted_arr1_subarrays = [];

    let arr2_subarrays = [],
        sorted_arr2_subarrays = [];

    //loop through array 1 making subarrays of two elements
    for (let i = 0; i < arr1.length; i += 2) {
        arr1_subarrays.push(arr1.slice(i, i + 2));
    }

    //loop through array 2 making subarrays of two elements.
    for (let i = 0; i < arr2.length; i += 2) {
        arr2_subarrays.push(arr2.slice(i, i + 2));
    }

    // sorting each subarray of arr1.
    for (let i = 0; i < arr1_subarrays.length; i += 2) {
        let result = merge(arr1_subarrays[i], arr1_subarrays[i + 1]);
        result.forEach((value) => sorted_arr1_subarrays.push(value));
    }

    // sorting each subarray of arr2.
    for (let i = 0; i < arr2_subarrays.length; i += 2) {
        let result = merge(arr2_subarrays[i], arr2_subarrays[i + 1]);
        result.forEach((value) => sorted_arr2_subarrays.push(value));
    }

    let result = merge(sorted_arr1_subarrays, sorted_arr2_subarrays);

    return result;
}

function partition(items, left, right) {
    //rem that left and right are pointers.

    let pivot = items[Math.floor((right + left) / 2)],
        i = left, //left pointer
        j = right; //right pointer

    while (i <= j) {
        //increment left pointer if the value is less than the pivot
        while (items[i] < pivot) {
            i++;
        }

        //decrement right pointer if the value is more than the pivot
        while (items[j] > pivot) {
            j--;
        }

        //else we swap.
        if (i <= j) {
            [items[i], items[j]] = [items[j], items[i]];
            i++;
            j--;
        }
    }

    //return the left pointer
    return i;
}

//-------------------------------------------Quick Sort-----------------------------------------------------//

function quickSort(items, left, right) {
    let index;

    if (items.length > 1) {
        index = partition(items, left, right); //get the left pointer returned

        if (left < index - 1) {
            //more elements on the left side
            quickSort(items, left, index - 1);
        }

        if (index < right) {
            //more elements on the right side
            quickSort(items, index, right);
        }
    }

    return items; //return the sorted array
}

//-------------------------------------------Heap Sort-----------------------------------------------------//
//how does it works: first step is to build an heap. That is done in the heapify function. Hepaify put the largest element at the root.

function heapSort(arr){
    var len = arr.length,
        end = len-1;
  
    heapify(arr, len);
    
    while(end > 0){
     swap(arr, end--, 0);
     siftDown(arr, 0, end);
    }
    return arr;
  }
  function heapify(arr, len){
    // break the array into root + two sides, to create tree (heap)
    var mid = Math.floor((len-2)/2);
    while(mid >= 0){
     siftDown(arr, mid--, len-1);    
   }
 }
 function siftDown(arr, start, end){
    var root = start,
        child = root*2 + 1,
        toSwap = root;
    while(child <= end){
       if(arr[toSwap] < arr[child]){
         swap(arr, toSwap, child);
       }
       if(child+1 <= end && arr[toSwap] < arr[child+1]){
         swap(arr, toSwap, child+1)
       }
       if(toSwap != root){
          swap(arr, root, toSwap);
          root = toSwap;
       }
       else{
          return; 
       }
       toSwap = root;
       child = root*2+1
   }
 }
 function swap(arr, i, j){
    var temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  } 

console.log("Bubble Sort of list [5,9,12,54,33,79] is : ")
console.log(bubbleSort([5, 9, 12, 54, 33, 79]));

console.log("\nSelection Sort of list [9,7,5,4,3,1] is : ")
console.log(selectionSort([9, 7, 5, 4, 3, 1]));

console.log("\nInsertion Sort of list [9,7,5,4,3,1] is : ")
console.log(insertionSort([9, 7, 5, 4, 3, 1]));

console.log("\nMerge Sort of list [70, 50, 30, 10, 20, 40, 60] is : ")
console.log(mergeSort([70, 50, 30, 10, 20, 40, 60]));

let items = [5, 3, 7, 6, 2, 9];
console.log("\nQuick Sort of list [5, 3, 7, 6, 2, 9] is : ")
console.log(quickSort(items, 0, items.length - 1))

console.log("\nHeap Sort of list [9,7,5,4,3,1] is : ")
console.log(heapSort([9, 7, 5, 4, 3, 1]));


