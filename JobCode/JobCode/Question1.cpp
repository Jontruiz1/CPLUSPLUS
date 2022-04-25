/*
*
* Jonathan Ruiz
*
*/
#include <vector>
#include <iostream>
#include <chrono>

struct ThreeDPoint
{
    int x;
    int y;
    int z;
};

void quick_sort(std::vector<ThreeDPoint>& points, int start, int end);
void bubble_sort(std::vector<ThreeDPoint>& points);
void merge_sort(std::vector<ThreeDPoint>& points, int const begin, int const end);


int main() {
    std::vector<ThreeDPoint> quick_set = { {3, 4, 5}, {42, 4000, 23}, { 10, 20, 30 }, {2, 3, 4}, {87, 2, 29}, {1, 2, 3}, {1, 23, 5},
                                        {1, 29, 11}, {23, 100, 5}, {440, 15, 66}, {55, 66, 23}, {6, 75, 12}, {23, 44, 12}, {343, 13, 33}, {500, 542, 333}, {8744, 122, 2943}, {5, 71, 19}, {57, 92, 15}, {47, 33, 5}, {33, 35, 91}, {13, 28, 10}, {44, 48, 97}, {42, 92, 9}, {43, 59, 9}, {78, 89, 87}, {69, 8, 31}, {91, 62, 48}, {85, 2, 27}, {31, 21, 73}, {38, 67, 27}, {71, 64, 34}, {90, 82, 85}, {42, 86, 70}, {13, 18, 51}, {36, 38, 88}, {63, 26, 63}, {23, 88, 65}, {48, 7, 17}, {54, 58, 3}, {55, 57, 25}, {46, 14, 67}, {49, 6, 100}, {27, 62, 61}, {88, 44, 15}, {4, 4, 20}, {21, 88, 17}, {64, 39, 78}, {15, 38, 25}, {15, 67, 27}, {22, 29, 19}, {3, 38, 37}, {2, 21, 12}, {57, 36, 4}, {42, 20, 77}, {98, 18, 31}, {35, 86, 13}, {47, 80, 61}, {99, 92, 38}, {100, 90, 8}, {84, 5, 22}, {48, 20, 67}, {72, 74, 77}, {63, 53, 72}, {2, 61, 82}, {76, 71, 66}, {46, 53, 46} };

    std::vector<ThreeDPoint> bubble_set = { {3, 4, 5}, {42, 4000, 23}, { 10, 20, 30 }, {2, 3, 4}, {87, 2, 29}, {1, 2, 3}, {1, 23, 5},
                                        {1, 29, 11}, {23, 100, 5}, {440, 15, 66}, {55, 66, 23}, {6, 75, 12}, {23, 44, 12}, {343, 13, 33}, {500, 542, 333}, {8744, 122, 2943}, {5, 71, 19}, {57, 92, 15}, {47, 33, 5}, {33, 35, 91}, {13, 28, 10}, {44, 48, 97}, {42, 92, 9}, {43, 59, 9}, {78, 89, 87}, {69, 8, 31}, {91, 62, 48}, {85, 2, 27}, {31, 21, 73}, {38, 67, 27}, {71, 64, 34}, {90, 82, 85}, {42, 86, 70}, {13, 18, 51}, {36, 38, 88}, {63, 26, 63}, {23, 88, 65}, {48, 7, 17}, {54, 58, 3}, {55, 57, 25}, {46, 14, 67}, {49, 6, 100}, {27, 62, 61}, {88, 44, 15}, {4, 4, 20}, {21, 88, 17}, {64, 39, 78}, {15, 38, 25}, {15, 67, 27}, {22, 29, 19}, {3, 38, 37}, {2, 21, 12}, {57, 36, 4}, {42, 20, 77}, {98, 18, 31}, {35, 86, 13}, {47, 80, 61}, {99, 92, 38}, {100, 90, 8}, {84, 5, 22}, {48, 20, 67}, {72, 74, 77}, {63, 53, 72}, {2, 61, 82}, {76, 71, 66}, {46, 53, 46} };

    std::vector<ThreeDPoint> merge_set = { {3, 4, 5}, {42, 4000, 23}, { 10, 20, 30 }, {2, 3, 4}, {87, 2, 29}, {1, 2, 3}, {1, 23, 5},
                                        {1, 29, 11}, {23, 100, 5}, {440, 15, 66}, {55, 66, 23}, {6, 75, 12}, {23, 44, 12}, {343, 13, 33}, {500, 542, 333}, {8744, 122, 2943}, {5, 71, 19}, {57, 92, 15}, {47, 33, 5}, {33, 35, 91}, {13, 28, 10}, {44, 48, 97}, {42, 92, 9}, {43, 59, 9}, {78, 89, 87}, {69, 8, 31}, {91, 62, 48}, {85, 2, 27}, {31, 21, 73}, {38, 67, 27}, {71, 64, 34}, {90, 82, 85}, {42, 86, 70}, {13, 18, 51}, {36, 38, 88}, {63, 26, 63}, {23, 88, 65}, {48, 7, 17}, {54, 58, 3}, {55, 57, 25}, {46, 14, 67}, {49, 6, 100}, {27, 62, 61}, {88, 44, 15}, {4, 4, 20}, {21, 88, 17}, {64, 39, 78}, {15, 38, 25}, {15, 67, 27}, {22, 29, 19}, {3, 38, 37}, {2, 21, 12}, {57, 36, 4}, {42, 20, 77}, {98, 18, 31}, {35, 86, 13}, {47, 80, 61}, {99, 92, 38}, {100, 90, 8}, {84, 5, 22}, {48, 20, 67}, {72, 74, 77}, {63, 53, 72}, {2, 61, 82}, {76, 71, 66}, {46, 53, 46} };

    size_t set_size = merge_set.size();

    auto quick_start = std::chrono::high_resolution_clock::now();
    quick_sort(quick_set, 0, set_size - 1);
    auto quick_stop = std::chrono::high_resolution_clock::now();
    auto quick_duration = std::chrono::duration_cast<std::chrono::microseconds>(quick_stop - quick_start);

    auto bubble_start = std::chrono::high_resolution_clock::now();
    bubble_sort(bubble_set);
    auto bubble_stop = std::chrono::high_resolution_clock::now();
    auto bubble_duration = std::chrono::duration_cast<std::chrono::microseconds>(bubble_stop - bubble_start);

    auto merge_start = std::chrono::high_resolution_clock::now();
    merge_sort(merge_set, 0, set_size - 1);
    auto merge_stop = std::chrono::high_resolution_clock::now();
    auto merge_duration = std::chrono::duration_cast<std::chrono::microseconds>(merge_stop - merge_start);


    std::cout << "Set size: " << set_size << std::endl;
    std::cout << "Merge Sort time in microseconds: " << merge_duration.count() << std::endl;
    std::cout << "Quick Sort time in microseconds: " << quick_duration.count() << std::endl;
    std::cout << "Optimized Bubble Sort time in microseconds: " << bubble_duration.count() << std::endl;
}



// magnitude function used for extra readability
float magnitude(ThreeDPoint point) { // Finding length of vector
    return (float)sqrt(point.x * point.x + point.y * point.y + point.z * point.z); // sqrt(x^2 + y^2 + z^2)
}


void bubble_sort(std::vector<ThreeDPoint>& points)
{
    float tmp1 = 0.0f;
    float tmp2 = 0.0f;
    bool done = false;
    size_t p_size = points.size() - 1;

    while (!done)
    {
        done = true;
        for (int i = 0, j = i + 1; i < p_size; ++i, ++j) {
            tmp1 = magnitude(points[i]);
            tmp2 = magnitude(points[j]);

            if (tmp2 < tmp1) {
                std::swap(points[i], points[j]);
                done = false;
            }
        }
    }
}

int partition(std::vector<ThreeDPoint>& points, int start, int end) {
    float pivot = magnitude(points[start]);

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (magnitude(points[i]) <= pivot) {
            count++;
        }
    }

    int pivot_index = start + count;
    std::swap(points[pivot_index], points[start]);

    int i = start;
    int j = end;

    while (i < pivot_index && j > pivot_index) {
        while (magnitude(points[i]) <= pivot) {
            i++;
        }
        while (magnitude(points[j]) > pivot) {
            j--;
        }
        if (i < pivot_index && j > pivot_index) {
            std::swap(points[i++], points[j--]);
        }
    }

    return pivot_index;

}

void quick_sort(std::vector<ThreeDPoint>& points, int start, int end) {
    if (start >= end) {
        return;
    }

    int p = partition(points, start, end);

    quick_sort(points, start, p - 1);
    quick_sort(points, p + 1, end);

}

void merge(std::vector<ThreeDPoint>& points, int const left, int const mid, int const right) {
    auto const left_size = mid - left + 1;
    auto const right_size = right - mid;

    auto* left_vector = new ThreeDPoint[left_size];
    auto* right_vector = new ThreeDPoint[right_size];


    // Fill in both temporary vector halves
    for (auto i = 0; i < left_size; i++) {
        left_vector[i] = points[left + i];
    }
    for (auto j = 0; j < right_size; j++) {
        right_vector[j] = points[mid + 1 + j];
    }

    // Set indices for subsets of vector
    auto i = 0;
    auto j = 0;
    int k = left;

    // Actual merge back into one vector
    while (i < left_size && j < right_size) {
        // Get magnitudes just for readability
        float tmp1 = magnitude(left_vector[i]);
        float tmp2 = magnitude(right_vector[j]);

        // Left is less than right, put left vector point into points
        if (tmp1 <= tmp2) {
            points[k] = left_vector[i];
            i++;
        }
        // Right is less than the left, put right vector point into points
        else {
            points[k] = right_vector[j];
            j++;
        }
        k++;
    }

    // If there are points left in the left sub-vector, copy them over
    while (i < left_size) {
        points[k] = left_vector[i];
        i++;
        k++;
    }
    // If there are points left in the right sub-vector, copy them over
    while (j < right_size) {
        points[k] = right_vector[j];
        j++;
        k++;
    }

}

void merge_sort(std::vector<ThreeDPoint>& points, int const begin, int const end) {
    if (begin >= end) {
        return;
    }
    auto mid = begin + (end - begin) / 2;
    merge_sort(points, begin, mid);
    merge_sort(points, mid + 1, end);
    merge(points, begin, mid, end);
}

