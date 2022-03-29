package JAVA_TEST.exam01;

public class CalculatorClass {
    public double input_NumA;
    public double input_NumB;
    public char op;
    public double result;
    
    // CalculatorClass() {
    //     super();
    // }

	// public CalculatorClass(double input_NumA, double input_NumB, char op, double result) {
	// 	super();
	// 	this.input_NumA = input_NumA;
	// 	this.input_NumB = input_NumB;
	// 	this.op = op;
	// 	this.result = result;
	// }
	
	public void add() {
		result = input_NumA + input_NumB;
		System.out.println(input_NumA + " + " + input_NumB + " = " + result);
	} 
	
	public void sub() {
		result = input_NumA - input_NumB;
		System.out.println(input_NumA + " - " + input_NumB + " = " + result);
	} 
	
	public void mul() {
		result = input_NumA * input_NumB;
		System.out.println(input_NumA + " * " + input_NumB + " = " + result);
	} 
	
	public void div() {
		result = input_NumA / input_NumB;
		System.out.println(input_NumA + " / " + input_NumB + " = " + result);
	}

	private void setInput_Values(double input_NumA2, char op2, double input_NumB2, double result2) {
		if(op == '+') { add(); }
		else if(op == '-') { sub(); }
		else if(op == '*') { mul(); }
		else if(op == '/') { div(); }
		return;
	}

	public void getInput_Values(double input_NumA2, char op2, double input_NumB2, double result2) {
		setInput_Values(this.input_NumA, this.op, this.input_NumB, this.result);
	}
}
