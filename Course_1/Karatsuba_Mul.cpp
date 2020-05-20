#include <iostream>
#include <string>

std::string karMul(std::string left, std::string right) {
  uint leftNum = left.size();
  uint rightNum = right.size();
  if (leftNum == 1 || rightNum == 1) {
    uint result = std::stoi(left) * std::stoi(right);
    return std::to_string(result);
  } 
  else {
    uint leftCutOffNum = leftNum / 2;
    uint rightCutOffNum = rightNum / 2;
    std::string a = left.substr(0, leftNum - leftCutOffNum);
    std::string b = left.substr(leftNum - leftCutOffNum);
    std::string c = right.substr(0, rightNum - rightCutOffNum);
    std::string d = right.substr(rightNum - rightCutOffNum);
    std::string step1 =
        karMul(a, c) + std::string(leftCutOffNum + rightCutOffNum, '0');
    std::string step2 = karMul(b, d);
    std::string step3 = karMul(a,d)+ std::string(leftCutOffNum, '0');
    std::string step4 = karMul(b,c)+ std::string(rightCutOffNum, '0');
    std::string step5 = stringAdd(step1, step2);
    std::string step6 = stringAdd(step3, step4);   
    std::string result = stringAdd(step5, step6);
    return result;
  }
}

std::string stringAdd(std::string left, std::string right) {
  std::string result;
  uint leftNum = left.size();
  uint rightNum = right.size();
  uint Max = std::max(leftNum, rightNum);
  left = std::string(Max - leftNum, '0') + left;
  right = std::string(Max - rightNum, '0') + right;
  uint Ten = 0;
  for (int i = 0; i < Max; i++) {
    int temp =
        (int)(left[Max - 1 - i]) - 48 + (int)(right[Max - 1 - i]) - 48 + Ten;
    if (temp < 10) {
      Ten = 0;
    } else {
      Ten = 1;
      temp = temp - 10;
    }
    result = std::to_string(temp) + result;
  }
  if (Ten == 1) {
    result = '1' + result;
  }
  return result;
}