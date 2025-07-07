#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For sort and transform
#include <cctype>    // For tolower

// Case-insensitive string comparison for sorting
bool caseInsensitiveCompare(const std::string& a, const std::string& b) {
    std::string lowerA = a;
    std::string lowerB = b;

    std::transform(lowerA.begin(), lowerA.end(), lowerA.begin(), ::tolower);
    std::transform(lowerB.begin(), lowerB.end(), lowerB.begin(), ::tolower);

    return lowerA < lowerB;
}

// Case-insensitive equality check
bool caseInsensitiveEqual(const std::string& a, const std::string& b) {
    if (a.size() != b.size()) return false;

    for (size_t i = 0; i < a.size(); ++i) {
        if (tolower(a[i]) != tolower(b[i])) return false;
    }
    return true;
}

// Ternary search with case-insensitive comparison
int ternarySearch(const std::vector<std::string>& playlist, const std::string& song, int left, int right) {
    if (left > right) return -1;

    int mid1 = left + (right - left) / 3;
    int mid2 = right - (right - left) / 3;

    if (caseInsensitiveEqual(playlist[mid1], song)) return mid1;
    if (caseInsensitiveEqual(playlist[mid2], song)) return mid2;

    std::string lowerSong = song;
    std::string lowerMid1 = playlist[mid1];
    std::string lowerMid2 = playlist[mid2];
    std::transform(lowerSong.begin(), lowerSong.end(), lowerSong.begin(), ::tolower);
    std::transform(lowerMid1.begin(), lowerMid1.end(), lowerMid1.begin(), ::tolower);
    std::transform(lowerMid2.begin(), lowerMid2.end(), lowerMid2.begin(), ::tolower);

    if (lowerSong < lowerMid1) {
        return ternarySearch(playlist, song, left, mid1 - 1);
    } else if (lowerSong > lowerMid2) {
        return ternarySearch(playlist, song, mid2 + 1, right);
    } else {
        return ternarySearch(playlist, song, mid1 + 1, mid2 - 1);
    }
}

int searchSong(const std::vector<std::string>& playlist, const std::string& song) {
    return ternarySearch(playlist, song, 0, playlist.size() - 1);
}

int main() {
    int n;
    std::cout << "Enter the number of songs in your playlist: ";
    std::cin >> n;
    std::cin.ignore(); // Flush newline

    std::vector<std::string> playlist;
    std::string song;

    std::cout << "Enter each song title:\n";
    for (int i = 0; i < n; ++i) {
        std::string songTitle;
        std::getline(std::cin, songTitle);
        playlist.push_back(songTitle);
    }

    // Sort the playlist case-insensitively
    std::sort(playlist.begin(), playlist.end(), caseInsensitiveCompare);

    std::cout << "Enter the song to search for: ";
    std::getline(std::cin, song);

    int index = searchSong(playlist, song);

    if (index != -1) {
        std::cout << "Song found at index (in sorted playlist): " << index << std::endl;
    } else {
        std::cout << "-1" << std::endl;
    }

    return 0;
}