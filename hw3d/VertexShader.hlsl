struct VSOut
{
	float4 color : COLOR;
	float4 pos : SV_POSITION;
};

VSOut main(float4 pos : POSITION, float4 color : COLOR)
{
	VSOut vso;
	vso.color = color;
	vso.pos = float4(pos.x, pos.y, 0.0f, 1.0f);
	return vso;
}