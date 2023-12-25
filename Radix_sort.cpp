void least_significant_digit_sort(int** nums, int size) {
    const int MAX_BIT = 32;  // Максимальное положение бита для целых чисел
    const int BUCKET_SIZE = 2;

    int* res = new int[size]; // Массив результата
    for (int i = 0; i < size; i++) {
        res[i] = 0;
    }
    int* cnt = new int[BUCKET_SIZE]; // Массив подсчета
    cnt[0] = cnt[1] = 0;

    for (int bit = 0; bit < MAX_BIT; bit++) {
        for (int j = 0; j < size; j++) {
            cnt[((*nums)[j] >> bit) & 1]++;
        }

        int pref[] = { 0, cnt[0] };
        for (int i = 0; i < size; i++) {
            res[pref[(*nums)[i] >> bit & 1]++] = (*nums)[i];
        }

        cnt[0] = cnt[1] = 0;
        for (int i = 0; i < size; i++) {
            (*nums)[i] = res[i];
        }
    }
}