from setuptools import setup, Distribution, find_packages

class BinaryDistribution(Distribution):
	def is_pure(self):
		return False

setup(	name='adrt', version='0.0',
		description='PDE Solver Package',
		url='https://github.com/dnry/adrt/',
		author='Yoon-gu Hwang',
		author_email='yz0624@gmail.com',
		license='BSD 3-clause "New" or "Revised License"',
		packages=find_packages(),
		install_requires=[
			'numpy',
		],
		distclass=BinaryDistribution,
		zip_safe=False)
