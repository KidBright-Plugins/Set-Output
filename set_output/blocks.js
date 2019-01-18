Blockly.Blocks["set_output.on"] = {
	init: function() {
		this.appendDummyInput()
			.appendField(Blockly.Msg.ON_OUTPUT_TITLE)
			.appendField(new Blockly.FieldDropdown([
				["OUT1", "26"],
				["OUT2", "27"],
			]), 'OUTPUT');
		this.setOutput(false, 'Number');
		this.setPreviousStatement(true);
		this.setNextStatement(true);
		this.setColour(58);
		this.setTooltip(Blockly.Msg.ON_OUTPUT_TOOLTIP);
		this.setHelpUrl(Blockly.Msg.ON_OUTPUT_HELPURL);
	}
};

Blockly.Blocks["set_output.off"] = {
	init: function() {
		this.appendDummyInput()
			.appendField(Blockly.Msg.OFF_OUTPUT_TITLE)
			.appendField(new Blockly.FieldDropdown([
				["OUT1", "26"],
				["OUT2", "27"],
			]), 'OUTPUT');
		this.setOutput(false, 'Number');
		this.setPreviousStatement(true);
		this.setNextStatement(true);
		this.setColour(58);
		this.setTooltip(Blockly.Msg.OFF_OUTPUT_TOOLTIP);
		this.setHelpUrl(Blockly.Msg.OFF_OUTPUT_HELPURL);
	}
};

Blockly.Blocks["set_output.pump"] = {
	init: function() {
		this.appendDummyInput()
			.appendField(Blockly.Msg.PUMP_CONTROL_TITLE)
			.appendField(new Blockly.FieldDropdown([
				["ON", "1"],
				["OFF", "0"],
			]), 'OUTPUT');
		this.setOutput(false, 'Number');
		this.setPreviousStatement(true);
		this.setNextStatement(true);
		this.setColour(58);
		this.setTooltip(Blockly.Msg.PUMP_CONTROL_TOOLTIP);
		this.setHelpUrl(Blockly.Msg.PUMP_CONTROL_HELPURL);
	}
};
