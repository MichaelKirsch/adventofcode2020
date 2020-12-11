//
// Created by micha on 11.12.2020.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

class day1 {
public:
    day1(){
        day1_a();
        day1_b();
    }

private:
    std::vector<int> input = {
            1889, 1974, 1983, 1590, 1530, 1402, 1731, 1935, 1404, 1763, 1733, 1234, 1706,
            633, 1524, 880, 1970, 1815, 1766, 1587, 1329, 1386, 1769, 1709, 1816, 1672, 75,
            1874, 1957, 1241, 1656, 1290, 1501, 1456, 1945, 1375, 1580, 1738, 1581, 1704, 1317,
            1651, 1971, 1614, 1668, 1694, 1862, 562, 1497, 1460, 1768, 1797, 1828, 728, 1826, 1519,
            1343, 1850, 1676, 1932, 1794, 1295, 1669, 1995, 1838, 1253, 1209, 1288, 1443, 1436, 1788,
            1732, 1289, 74, 1659, 1264, 1533, 1938, 1401, 1748, 1445, 1941, 1924, 1807, 1772, 1761, 1805,
            1658, 927, 1294, 1643, 1308, 1472, 1822, 1332, 1220, 1947, 1352, 1782, 1851, 1789, 1551, 1490,
            1690, 1989, 1052, 1340, 1437, 1378, 1316, 1835, 1967, 1885, 1487, 1452, 1480, 1943, 1760, 1897,
            1632, 1354, 1843, 1698, 1467, 1625, 1421, 1482, 1275, 1341, 1422, 1586, 1283, 1686, 1640, 1987,
            1603, 1131, 1777, 1864, 1529, 1858, 1665, 1326, 1804, 1285, 1449, 1866, 1762, 1708, 1699, 1622,
            1774, 1993, 1796, 1825, 1786, 1518, 1726, 1577, 1545, 1494, 1756, 1611, 2005, 1888, 1930, 1538,
            1744, 894, 1537, 1513, 1650, 1898, 1719, 1615, 1646, 1758, 1495, 1717, 1670, 1759, 1865, 1793,
            1484, 1702, 1861, 1330, 1767, 1549, 1536, 717, 2007, 1902, 1583, 1682, 1374, 1892, 1839, 1771, 1624
    };



    void day1_a() {
        //find the numbers that add to 2020 and then multiply them
        std::sort(input.begin(), input.end()); //sort vector
        int steps_needed = 0;
        for (int it = input.size() - 1; it > 0; it--) {
            for (int it_back = 0; it_back < input.size() - 1; it_back++) {
                int sum = input[it] + input[it_back];
                steps_needed++;
                if (sum > 2020) { break; }
                if (sum == 2020) {
                    std::cout << "found it!!Result is:" << (input[it] * input[it_back]) << " Needed " << steps_needed
                              << " steps to find it" << std::endl;
                    return;
                }
            }
        }
    }

    void day1_b() {
        //find 3 numbers that add up to 2020

        std::sort(input.begin(), input.end()); //sort vector
        int steps_needed = 0;
        for (int it = input.size() - 1; it > 0; it--) {
            for (int it_back = 0; it_back < input.size() - 1; it_back++) {
                int sum_between = input[it] + input[it_back];
                steps_needed++;
                if (sum_between > 2020) { break; }
                for (int third = it_back; third < input.size() - 1; third++) {
                    steps_needed++;
                    int third_sum = sum_between + input[third];
                    if (third_sum > 2020) {break;}
                    if (third_sum == 2020) {
                        std::cout << "found it!!Result is:" << input[it] * input[it_back] * input[third] << " Needed "
                                  << steps_needed
                                  << " steps to find it" << std::endl;
                        return;
                    }
                }

            }
        }
    }
};


