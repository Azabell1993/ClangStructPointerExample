package JAVA_TEST.exam01;

public class runMain {
	public static void main(String[] args) {
        // 객체 생성 
		CalculatorClass calculator = new CalculatorClass();
        //필드 생성
		calculator.input_NumA = 10;
		calculator.input_NumB = 20;
		calculator.op = '+';
        //호출
		calculator.getInput_Values(calculator.input_NumA, calculator.op, calculator.input_NumB, calculator.result);

        // 객체 생성 
		CalculatorClass calculator2 = new CalculatorClass();
        //필드 생성
		calculator2.input_NumA = 50;
		calculator2.input_NumB = 20;
		calculator2.op = '-';
        //호출
		calculator2.getInput_Values(calculator.input_NumA, calculator.op, calculator.input_NumB, calculator.result);

        // 객체 생성 
		CalculatorClass calculator3 = new CalculatorClass();
        //필드 생성
		calculator3.input_NumA = 10;
		calculator3.input_NumB = 100;
		calculator3.op = '/';
        //호출
		calculator3.getInput_Values(calculator.input_NumA, calculator.op, calculator.input_NumB, calculator.result);

        // 객체 생성 
		CalculatorClass calculator4 = new CalculatorClass();
        //필드 생성
		calculator4.input_NumA = 60;
		calculator4.input_NumB = 40;
		calculator4.op = '*';
        //호출
		calculator4.getInput_Values(calculator.input_NumA, calculator.op, calculator.input_NumB, calculator.result);
	}
}