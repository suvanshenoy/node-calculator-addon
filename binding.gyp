{
	'targets':[
	{
		'target_name' : 'calculator',
		'cflags_cxx': ['-std=c++23'],
		'sources':[
			'src/calculator/main.cpp',
		],
		"include_dirs":[
			    "<!@(node -p \"require('node-addon-api').include\")"	
		],

		'cflags_cc': ['-D NAPI_CPP_EXCEPTIONS','-fexceptions','-std=c++23']
	},
	]

}
