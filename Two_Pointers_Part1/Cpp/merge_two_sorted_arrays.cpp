void merge(int *arr, int start, int mid, int end) {
    int temp[end-start+1];
    int i = start, j = mid+1, k = 0;
    while(i <= mid and j <= end) {
        if(arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
            k++;
        } else {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    while(i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while(j <= end) {
        temp[k] = arr[j];
        j++;
        k++;
    }
    for(int i = start; i<= end; i++) {
        arr[i] = temp[i-start];
    }
}