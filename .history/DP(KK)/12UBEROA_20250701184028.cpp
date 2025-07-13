// Given two arrays; a and b -> you can start at index 1 from any array and end your journey at index n on an array 

// -> If you are at i you can can jump to i+1 on same array or different array 

// -> -1000000000 <= a[i],b[i]<= 10000000000 

// -> Please output total number of journeys which have even sum and total number of journeys which have odd sum; 

// -> dpa_even_[1] = if number a[1] is even then answer is 1 else 0

// -> dpa_even[2] = considering both array till index “2” and a[2] is forcefully selected when journey ends at index “2”; 

// -> dpb_even[i] = 

// -> dpa_odd[i] = 

// -> dpb_odd[i] = number of journeys ending at b[i] whose sum is odd; 

// -> Total even journeys = dp_a_even[n] + dp_b_even[n] 


// -> if b[i] % 2 == 0 
// -> dpb_even[i] = dpb_even[i-1] + dpa_even[i-1] 
// -> if b[i] % 2 !=0 
// -> dpb_even[i] = dpb_odd[i-1] + dpa_odd[i-1] 

// -> Similarly make the formula for dpa_odd[],dpb_odd,dpa_even[]...

// C++ https://ideone.com/UWpbIY 
// Java. https://ideone.com/TgQJ2C 
// Py https://www.jdoodle.com/ia/1Aup 












