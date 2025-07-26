vector<int> findMajority(vector<int>& arr) {
    int count1 = 0, count2 = 0;
    int ele1 = 0, el2 = 0;

    // First pass find two potential candidates
    for (int num : arr) {
        if (count1 == 0 && num != el2) {
            ele1 = num;
            count1 = 1;
        } 
        else if (count2 == 0 && num != ele1) {
            el2 = num;
            count2 = 1;
        } 
        else if (num == ele1) {
            count1++;
        } 
        else if (num == el2) {
            count2++;
        } 
        else {
            count1--;
            count2--;
        }
    }


    // Second pass verify actual counts of the candidates
    count1 = 0, count2 = 0;
    for (int num : arr) {
        if (num == ele1) count1++;
        if (num == el2) count2++;
    }

    int votes = arr.size();
    vector<int> res;

    // Add valid candidates to the result
    if (count1 > votes / 3) res.push_back(ele1);
    if (count2 > votes / 3 && el2 != ele1) res.push_back(el2);

    // Ensure result is in increasing order (at most 2 elements)
    if (res.size() == 2 && res[0] > res[1]) {
        swap(res[0], res[1]);
    }

    return res;
}