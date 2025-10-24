#include<iostream>
using namespace std;

int getLen(char* arr) {
    if (arr == nullptr) return 0;
    int len = 0;
    for (int i = 0; arr[i] != '\0'; i++) {
        len++;
    }
    return len;
}

void reverse_num(char* &arr) {
    int st = 0, end = getLen(arr) - 1;
    while (st < end) {
        char temp = arr[st];
        arr[st] = arr[end];
        arr[end] = temp;
        st++, end--;
    }
}

void regrow(char*& arr, int& size, char input) {
    char* new_arr = new char[size + 1];    
    for (int i = 0; i < size; i++) {
        new_arr[i] = arr[i];
    }
    
    new_arr[size] = input;
    size++;
    delete[] arr;
    arr = new_arr;
}

void print_complex_number(char* c_number, char* message) {
    cout << message;
    for (int i = 0; c_number[i] != '\0'; i++) {
        cout << c_number[i];
    }
}
void extract_cnInts(char* com_num, int& num1, int& num2) {
    int i = 0;
    int num = 0;
    bool is_negative = false;

    if (com_num[i] == '-') {
        is_negative = true;
        i++; 
    }
    
    while (com_num[i] >= '0' && com_num[i] <= '9') {
        num = num * 10 + (com_num[i] - '0');
        i++;
    }
    
    num1 = is_negative ? -num : num;
    num = 0; 
    is_negative = false;

    while (com_num[i] != '\0' && (com_num[i] < '0' || com_num[i] > '9')) {
        if (com_num[i] == '-') {
             is_negative = true;
        }
        i++;
    }

    while (com_num[i] >= '0' && com_num[i] <= '9') {
        num = num * 10 + (com_num[i] - '0');
        i++;
    }

    num2 = is_negative ? -num : num;
}
void read_complex_number(char*& complex_number, int& cn_size) {
    cout << "Enter a complex number: ";
    char garbage;
    if (complex_number) {
        delete[] complex_number;
        complex_number = nullptr;
        cn_size = 0;
    }
    
    while (true) {
        cin.get(garbage);
        if (garbage == '\n') {
            break;
        }
        regrow(complex_number, cn_size, garbage);
    }
    regrow(complex_number, cn_size, '\0');
}

char* intTOchar(int number) {
    char* ar = nullptr;
    int size = 0;
    bool is_negative = false;

    if (number == 0){
        regrow(ar, size, '0');
        regrow(ar, size, '\0');
        return ar;
    } 

    if (number < 0) {
        is_negative = true;
        number *= -1;
    }

    int num = 0;
    while (number != 0) {
        num = number % 10;
        number /= 10;
        regrow(ar, size, '0' + num);
    }
    
    if (is_negative) {
        regrow(ar, size, '-'); 
    }

    regrow(ar, size, '\0');
    reverse_num(ar);
    return ar;
}

char* get_resultant_complex_num(char* real_part_str, char* imag_part_str) {
    int len1 = getLen(real_part_str);
    int len2 = getLen(imag_part_str);
    
    bool imag_is_negative = (imag_part_str[0] == '-');
    
    int size_separator = 3; // ' + ' or ' - '
    int size_imag_digits = imag_is_negative ? len2 - 1 : len2; // Use magnitude length
    
    int required_size = len1 + size_separator + size_imag_digits + 2; 
    
    char* resultant_number = new char[required_size];
    int i = 0, counter = 0;
    
    while (real_part_str[i] != '\0') {
        resultant_number[counter++] = real_part_str[i++];
    }
    
    resultant_number[counter++] = ' ';
    
    if (!imag_is_negative) {
        resultant_number[counter++] = '+';
        resultant_number[counter++] = ' ';
        i = 0; 
	} else {
        resultant_number[counter++] = '-';
        resultant_number[counter++] = ' ';
        i = 1;
	}
    while (imag_part_str[i] != '\0') {
        resultant_number[counter++] = imag_part_str[i++];
    }
    
    resultant_number[counter++] = 'i';
    resultant_number[counter++] = '\0';
    
    return resultant_number;
}

int main() {
    int num1_to_mul, num2_to_mul;
    char* cn_1 = nullptr;
    int cn_1_size = 0;
    char* cn_2 = nullptr;
    int cn_2_size = 0;

    read_complex_number(cn_1, cn_1_size);
    read_complex_number(cn_2, cn_2_size);
    
    int num1, num2;
    extract_cnInts(cn_1, num1, num2);
    extract_cnInts(cn_2, num1_to_mul, num2_to_mul);

    int real_add = num1 + num1_to_mul;
    int imag_add = num2 + num2_to_mul;

    char* ar1_add = intTOchar(real_add);
    char* ar2_add = intTOchar(imag_add);
    
    char* complex_addition = get_resultant_complex_num(ar1_add, ar2_add);

    
    int realPart = (num1 * num1_to_mul) - (num2 * num2_to_mul);
    int imagPart = (num1 * num2_to_mul) + (num2 * num1_to_mul);
    
    char* ar1_mul = intTOchar(realPart);
    char* ar2_mul = intTOchar(imagPart);
    
    char* complex_multiplication = get_resultant_complex_num(ar1_mul, ar2_mul);
    print_complex_number(complex_addition, "Complex Addition: ");
    cout << endl;
    print_complex_number(complex_multiplication, "Complex Multiplication: ");
    cout << endl;

    delete[] ar1_add;
    delete[] ar2_add;
    delete[] complex_addition;
    delete[] ar1_mul;
    delete[] ar2_mul;
    delete[] complex_multiplication;
    delete[] cn_1;
    delete[] cn_2;

    return 0;
}
