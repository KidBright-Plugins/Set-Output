Blockly.JavaScript["set_output.on"] = function(block) {
	return 'DEV_IO.set_output().on('+block.getFieldValue('OUTPUT') +');\n';
};

Blockly.JavaScript["set_output.off"] = function(block) {
	return 'DEV_IO.set_output().off('+block.getFieldValue('OUTPUT') +');\n';
};

Blockly.JavaScript["set_output.pump"] = function(block) {
	return 'DEV_IO.set_output().pump('+block.getFieldValue('OUTPUT') +');\n';
};



