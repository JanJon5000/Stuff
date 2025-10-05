double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int counter = 0;
    int prev = 0; int curr = 0;
    int middle = (nums1Size + nums2Size)/2;
    int i = 0; int j = 0;
    while(counter <= middle){
        prev = curr;
        if(i<nums1Size && (j>=nums2Size || nums1[i]>=nums2[j]))
            curr = nums1[i++];
        else
            curr = nums2[j++];
        counter++;
    }
    if((nums1Size + nums2Size)%2 == 1)
        return curr;
    else
        return (curr + prev)/2.0;
}