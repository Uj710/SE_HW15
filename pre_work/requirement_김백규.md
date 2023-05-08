1. 수정된 Requirement list

<table>
	<thead>
		<tr>
			<td>No.</td>
			<td>Requirement</td>
            <td>Use Case(s)</td>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td>1</td>
			<td>사용자의 기본 정보와 ID/Password를 기록한다.</td>
            <td>회원가입</td>
		</tr>
        <tr>
			<td>2</td>
			<td>사용자의 시스템 사용 권한을 소멸한다.</td>
            <td>회원탈퇴</td>
		</tr>
        <tr>
			<td>3</td>
			<td>사용자가 시스템 사용 권한을 얻기 위해 ID와 password를 확인한다.</td>
            <td>로그인</td>
		</tr>
        <tr>
			<td>4</td>
			<td>사용자가 시스템에서 로그아웃한다.</td>
            <td>로그아웃</td>
		</tr>
        <tr>
			<td>5</td>
			<td>사용자에게 채용 정보 리스트를 보여준다.</td>
            <td>채용 정보 리스트 조회</td>
		</tr>
        <tr>
			<td>6</td>
			<td>업무, 인원 수, 신청 마감일 등의 채용 정보를 기록한다.</td>
            <td>채용 정보 등록</td>
		</tr>
        <tr>
			<td>7</td>
			<td>업무, 인원 수, 신청 마감일 등의 채용 정보를 수정한다.</td>
            <td>채용 정보 수정</td>
		</tr>
        <tr>
			<td>8</td>
			<td>업무, 인원 수, 신청 마감일 등의 채용 정보를 삭제한다.</td>
            <td>채용 정보 삭제</td>
		</tr>
        <tr>
			<td>9</td>
			<td>지원자 수가 도달한 채용을 조기 마감한다.</td>
            <td>채용 조기 마감</td>
		</tr>
        <tr>
			<td>10</td>
			<td>마감일이 지났거나, 마감 처리된 채용 정보 리스트를 조회한다.</td>
            <td>마감 채용 조회</td>
		</tr>
        <tr>
			<td>11</td>
			<td>회사 이름 혹은 업무로 검색할 때의 결과로 채용 정보 리스트를 출력한다.</td>
            <td>채용 정보 검색</td>
		</tr>
        <tr>
			<td>12</td>
			<td>원하는 채용 정보를 선택할 때 해당되는 채용 정보를 출력한다.</td>
            <td>채용 지원</td>
		</tr>
        <tr>
			<td>13</td>
			<td>본인이 지원한 지원 정보를 조회한다.</td>
            <td>채용 정보 조회</td>
		</tr>
        <tr>
			<td>14</td>
			<td>마감 시간이 지나지 않은 지원 정보를 취소한다.</td>
            <td>채용 지원 취소</td>
		</tr>
        <tr>
			<td>15</td>
			<td>마감 시간이 지난 지원 정보를 임의로 삭제한다.</td>
            <td>지원 정보 삭제</td>
		</tr>
        <tr>
			<td>16</td>
			<td>채용 정보 및 지원 정보를 출력한다.</td>
            <td>지원 정보 통계</td>
		</tr>
	</tbody>
</table>

2. 수정된 use case diagram과 use case description

![drawio](https://user-images.githubusercontent.com/105341168/236754334-5031acfc-7d96-44bf-a81e-ea1447698d19.png)

(2) 회원탈퇴

<table>
	<thead>
		<tr>
			<td>Actor Action</td>
			<td>System Response</td>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td>1. 회원탈퇴를 선택한다.</td>
			<td>2. 회원 탈퇴가 되었음을 확인하는 메시지를 제공한다.</td>
		</tr>
	</tbody>
</table>

(10) 마감 내역 조회

<table>
	<thead>
		<tr>
			<td>Actor Action</td>
			<td>System Response</td>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td>1. 마감 내역 조회를 선택한다.</td>
			<td>2. 마감일이 지났거나 마감 처리된 채용 정보 내역을 제공한다.</td>
		</tr>
        <tr>
			<td></td>
			<td>3. 마감일의 오름차순으로 정렬하여 신청 마감일 정보를 출력한다.</td>
		</tr>
	</tbody>
</table>

(11) 채용 정보 검색

<table>
	<thead>
		<tr>
			<td>Actor Action</td>
			<td>System Response</td>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td>1. None</td>
			<td>2. 회사 이름 혹은 회사 업무를 선택해 검색한다.</td>
		</tr>
        <tr>
			<td>3. 회사 이름 혹은 회사 업무를 선택해 검색한다.</td>
			<td>4. 현재 시점에서 마감일이 지나지 않은 채용 정보 리스트를 검색 결과로 출력한다.</td>
		</tr>
        <tr>
			<td></td>
			<td>5. 회사이름의 오름차순을 디폴트 정렬 기준으로 제공한다.</td>
		</tr>
	</tbody>
</table>

(12) 채용 지원

<table>
	<thead>
		<tr>
			<td>Actor Action</td>
			<td>System Response</td>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td>1. 희망하는 채용 정보를 선택한다.</td>
			<td>2.해당 채용 정보에 대한 회사 이름, 인원수, 신청 마감일 정보가 들어 있는 상세 화면을 제공한다.</td>
		</tr>
        <tr>
			<td>3. 희망하는 채용 정보를 지원한다.</td>
			<td>4. 지원이 완료되었다는 메시지를 제공 한다.</td>
		</tr>
	</tbody>
</table>

(13) 지원 정보 조회

<table>
	<thead>
		<tr>
			<td>Actor Action</td>
			<td>System Response</td>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td>1. 지원 정보 조회를 선택한다.</td>
			<td>2. 해당 회원의 지원 정보 (회사 이름, 인원수, 신청 마감일)를 회사 이름의 오름차순으로 정렬해 출력한다.</td>
		</tr>
        <tr>
            <td colspan="2">Inclusions</td>
        </tr>
        <tr>
            <td colspan="2">- 지원 정보 삭제 이전에, 일반회원은 지원 정보 조회를 해야 한다.</td>
        </tr>
        <tr>
            <td colspan="2">- 채용 지원 취소 이전에, 일반회원은 지원 정보 조회를 해야 한다.</td>
        </tr>
	</tbody>
</table>

(14) 채용 지원 취소

<table>
	<thead>
		<tr>
			<td>Actor Action</td>
			<td>System Response</td>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td>1. 마감일이 지나지 않은 지원 정보를 선택하여 지원을 취소한다.</td>
			<td>2. 지원 취소가 되었음을 확인하는 메시지를 제공한다.</td>
		</tr>
	</tbody>
</table>

(15) 지원 정보 삭제

<table>
	<thead>
		<tr>
			<td>Actor Action</td>
			<td>System Response</td>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td>1. 마감 시간이 지난 지원정보를 삭제한다.</td>
			<td>2. 지원 정보가 삭제되었음을 확인하는 메시지를 제공한다.</td>
		</tr>
	</tbody>
</table>

(16) 지원 정보 통계

<table>
	<thead>
		<tr>
			<td>Actor Action</td>
			<td>System Response</td>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td>1. 통계 기능을 선택한다</td>
			<td>2.회사 회원에게 등록한 모든 채용 정보에 대해 업무별 지원자 수를 출력한다. 일반 회원에게 본인이 지원한 정보에 대해 월별 지원 횟수를 출력한다.</td>
		</tr>
	</tbody>
</table>