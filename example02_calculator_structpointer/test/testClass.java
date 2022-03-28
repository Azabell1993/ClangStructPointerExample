package example02_calculator_structpointer.test;

public class testMain {
	public static void main(String[] args) {
        //객체 생성
        subtest test = new subtest();
        test.operand1 = 10;
        test.operand2 = 30;
        test.operator = '+';
        test.result = 0;
        test.add(test.operand1, test.operand2, test.result);
        System.out.println(test.result);
        }
}

