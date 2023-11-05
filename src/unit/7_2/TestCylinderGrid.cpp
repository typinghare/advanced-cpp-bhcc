//
//  TestCylinderGrid.cpp
//  CSC284SU2021
//
//  Created by Liz Miller on 7/29/21.
//

#include <iostream>
#include <vector>
#include "CylinderGrid.h"

using namespace std;

CylinderGrid createObject()
{
    cout << "in createObject" << endl;
    return CylinderGrid(100, 100);
}

int main()
{
    vector<CylinderGrid> vec;
    for (int i = 0; i < 2; ++i) {
        cout << "Iteration " << i << endl;
        vec.push_back(CylinderGrid(100, 100));
        cout << endl;
    }
    cout << "CylinderGrid s2(100,100)" <<endl<<endl;
    CylinderGrid s2(100,100);
    cout << "CylinderGrid s3 = s2" <<endl<<endl;
    
    CylinderGrid s3 = s2;
    cout << "CylinderGrid s(100,100)" <<endl<<endl;
    
    CylinderGrid s(100,100);
    
    s = createObject();
    
    cout << "done " << s.getCylinderAt(50, 50).toString() << endl<<endl;
    cout << "s2 = s" <<endl<<endl;
    
    s2 = s;

    return 0;
}
