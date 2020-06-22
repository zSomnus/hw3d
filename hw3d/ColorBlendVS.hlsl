cbuffer CBuf
{
	matrix transform;
};

struct VSOut
{
	float4 color : COLOR;
	float4 pos : SV_POSITION;
};

VSOut main( float4 pos : POSITION, float4 color : COLOR )
{
	VSOut vso;
	vso.pos = mul(pos, transform);
	vso.color = color;
	return vso;
}